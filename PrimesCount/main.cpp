//
//  main.cpp
//  PrimesCount
//
//  Created by 黄美强 on 15/5/6.
//  Copyright (c) 2015年 黄 美强. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int countPrimes(int n) {
    if(n<=2)
        return 0;
    if(n==3)
        return 1;
    if(n<=5)
        return 2;
    vector<int> primes;
    vector<int>::iterator it;
    bool *mark = new bool[n];
    
    for(int i = 0; i < n; i++){
        mark[i] = true;
    }
    
    primes.push_back(3);
    
    for(int i = 0; i < n; i += 2){
        mark[i] = false;
    }
    mark[1] = false;
    mark[2] = true;
    
    for(int i = 3; i < n; i += 2){
        if(mark[i]){
            int j = 2;
            while(j*i<n){
                mark[i*j] = false;
                j++;
            }
        }
    }
    int count = 0;
    
    for(int i = 1; i < n; i++){
        if(mark[i]){
            count++;
        }
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    std::cout << countPrimes(10);
    return 0;
}
