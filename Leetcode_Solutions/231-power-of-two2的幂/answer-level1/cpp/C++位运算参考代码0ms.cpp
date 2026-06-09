![image.png](https://pic.leetcode-cn.com/2757911c1a1bc52f7086335e34f2610fe725fc7eafe66dbdad58977de13b2cdb-image.png)

```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long a = 1;
        while(a <= n){
            if(a == n)
                return true;
            else
                a = a<<1;
        }
        return false;
    }
};
```
