### 解题思路
1. 实现一个判断质数的func
2. 统计[L, R]这个区间的二进制计数中为质数的个数

### 代码

```cpp
class Solution {
public:
    bool isPrime(int n){
        if(n <= 3) return n > 1;
        if(n % 2 == 0) return false;
        int sq = sqrt(n);
        for(int i = 3; i <= sq; i += 2){
            if(n % i == 0) return false;
        }
        return true;
    }

    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int i = L; i <= R; i++){
            int cnt = 0;
            for(int j = 0; j < 32; j++){
                if(i & (1 << j)) cnt++;
            }
            if(isPrime(cnt)) ans ++;
        }
        return ans;
    }
};
```