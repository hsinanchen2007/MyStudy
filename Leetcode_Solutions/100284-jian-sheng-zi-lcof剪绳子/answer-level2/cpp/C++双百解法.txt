![QQ截图20200407200305.png](https://pic.leetcode-cn.com/4d925dfb7675cb72e32f8defc638f8bed09d579de1d6d9e8b9d96761f8576063-QQ%E6%88%AA%E5%9B%BE20200407200305.png)

### 解题思路
若绳子的根数相同，则每根绳子的长度越平均，得到的积越大，因此让每根绳子尽量等于n/m；
当单根绳长为n/m，乘积为（n/m）^m,其大小随着m的变大，先增大后减小，当求得的值小于当前值时，跳出循环；

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        int m = 2;
        int ans = 1;
        while(1){
            int k = n/m;
            int r = n%m;
            int mul = pow(k, m-r) * pow(k+1, r);
            if(mul >= ans) ans = mul;
            else break;
            m++;
        }
        return ans;
    }
};
```