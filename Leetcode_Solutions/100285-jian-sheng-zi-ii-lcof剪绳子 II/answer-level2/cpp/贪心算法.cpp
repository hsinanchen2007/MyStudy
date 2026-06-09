### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int mod = 1000000007;
        long long res = 1;
        while(n>4){
            res*=3;
            res%=mod;
            n-=3;
        }
        res = res*n%mod;
        return res;
    }
};
```