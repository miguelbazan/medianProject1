//  main.cpp
//  Proyecto1Mediana
//
//  Created by Miguel Bazan on 2/29/16.
//  Copyright © 2016 Miguel Bazan. All rights reserved.
//  Miguel Bazan A01281010
//  Ricardo Licea A01280892

#include <iostream>
#include<cstdio>
#include <iomanip>
using namespace std;

float reduce(float fArr[], int iN)
{
    return iN % 2 == 0 ?  (fArr[iN/2] + fArr[iN/2-1])/2 :  fArr[iN/2];
}
float medio(float iArrA[], float iArrB[], int iN)
{
    int m1,m2;
    
    if (iN <= 0)
        
        return -1;
    
    if (iN == 1)
        
        return (iArrA[0] + iArrB[0])/2;
    
    if (iN == 2)
        
        return (max(iArrA[0], iArrB[0]) + min(iArrA[1], iArrB[1])) / 2;
    
    m1 = reduce(iArrA, iN);
    m2 = reduce(iArrB, iN);
    
    if (m1 == m2)
        
        return m1;
    
    if (m1 < m2)
        
        return (iN % 2 == 0) ? medio(iArrA + iN/2 - 1, iArrB, iN - iN/2 +1) :medio(iArrA + iN/2, iArrB, iN - iN/2);
    
    else
    {
        return (iN % 2 == 0) ? medio(iArrB + iN/2 - 1, iArrA, iN - iN/2 + 1):medio(iArrB + iN/2, iArrA, iN - iN/2);
    }
}
int main(int argc, const char * argv[])
{
    
    int iCasos,iSize;
    float iArrA[100], iArrB[100];
    
    cin>>iCasos;
    
    for (int iR = 1; iR <= iCasos; iR++)
    {
        cin>>iSize;
        
        for (int iA = 0; iA<iSize; iA++)
        {
            cin>>iArrA[iA];
        }
        for (int iC = 0; iC<iSize; iC++)
        {
            cin>>iArrB[iC];
        }
      //  cout<<endl;
        
        cout << "Median case "<<iR<<": "<<fixed<<setprecision(2)<<medio(iArrA, iArrB, iSize)<<endl;
    }
    return 0;
}