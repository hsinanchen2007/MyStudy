### 解题思路
1. 计数&判断质数
2. 素数表

### 代码

```c++ []
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int N = 0;
        for(int i=L; i<=R; ++i){
            if(isPrime(countOne(i))) ++N;
        }
        return N;
    }

    int countOne(int x){
        int res = 0;
        while(x > 0){
            if((x & 0x01)==1) ++res;
            x>>=1;
        }
        return res;
    }

    bool isPrime(int x){
        if(x == 1)
            return false;
        
        for(int i=2; i<=sqrt(x); ++i){
            if(x % i ==0)
                return false;
        }
        return true;
    }
};
```
```c++ []
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        // 素数集合, 到10^6, 使用20以内的素数表可以求解
        unordered_set<int> primes({2,3,5,7,11,13,17, 19});
        int res = 0;
        for(int i=L; i<=R; ++i){
            int s=0;
            for(int k=i; k; k>>=1) s+=k&0x01;
            if(primes.count(s)) ++res;
        }
        return res;
    }
};
```