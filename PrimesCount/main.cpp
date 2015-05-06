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
    if(n<=3)
        return 1;
    vector<int> primes;
    vector<int>::iterator it;
    primes.push_back(3);
    
    for(int i = 5; i<n; i+=2){
        bool isprime = true;
        vector<int>::iterator it1;
        it1 = primes.end()-1;
        if((*it1) <= (int)sqrt(i))
            it1 = primes.end();
        else{
            for(it1 = primes.begin(); it1 != primes.end(); it1++){
                if((*it1) >= (int)sqrt(i)){
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
        if(isprime)
            primes.push_back(i);
    }
    return primes.size()+1;
}

int main(int argc, const char * argv[]) {
    std::cout << countPrimes(999983);
    return 0;
}
