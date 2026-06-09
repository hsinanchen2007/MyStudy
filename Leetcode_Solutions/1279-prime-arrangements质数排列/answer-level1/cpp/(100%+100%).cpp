### 解题思路
全排列+判断质数

### 代码

```cpp
class Solution {
public:
    // 全排列
    long Array(int n){
        if(n==0){
            return 1;
        }
        long long result = (n*Array(n-1))%1000000007;
        return result;
    }
    int FindPrime(int n){
        if(n==1){
            return 0;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }
    int numPrimeArrangements(int n) {
        int prime_num=0;
        for(int i=1;i<=n;i++){
            prime_num += FindPrime(i);
        }
        int other_num=n-prime_num;
        long long result = (Array(prime_num)*Array(other_num))%1000000007;
        return result;
    }
};
```