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
    
    for(int i = 5; i < n; i += 2){
        if(mark[i]){
            bool isprime = true;
            
            vector<int>::iterator it1;
            it1 = primes.end()-1;
            if((*it1) <= (int)sqrt(i))
                it1 = primes.end();
            else{
                for(it1 = primes.begin(); it1 != primes.end(); it1++){
                    if((*it1) > (int)sqrt(i)){
                        break;
                    }
                }
            }
            
            for(it = primes.begin(); it != it1; it++){
                if(i%(*it) == 0){
                    isprime = false;
                    break;
                }
            }
            if(isprime){
                primes.push_back(i);
                int j = 2;
                while(j*i<n){
                    mark[i*j] = false;
                    j++;
                }
            }
        }
    }
    
    delete [] mark;
    return (int)primes.size()+1;
}

int main(int argc, const char * argv[]) {
    std::cout << countPrimes(7);
    return 0;
}
