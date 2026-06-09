### 解题思路
每个数只被其最小质因子筛去

### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int primes[n];
        bool isPrime[n];
        for(int i=0;i<n;i++){
            primes[i]=0;
            isPrime[i]=true;
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(isPrime[i])    //如果i是一个质数
            primes[count++]=i;//把i储存入primes数组中，计数器加一
//关键部分，与埃氏筛法不同，欧拉筛法让每个数都进行筛选
            for(int j=0;j<count&&i*primes[j]<n;j++){
                isPrime[i*primes[j]]=false;//
                if(i%primes[j]==0)//i%primes[j]==0，代表primes[j+1]不是最小质因子
                    //i*primes[j+1]将在后续i递增时筛去
                break;
            }
        }
        return count;
    }
};
```