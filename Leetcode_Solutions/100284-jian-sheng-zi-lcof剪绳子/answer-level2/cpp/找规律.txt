### 解题思路
参考链接https://www.cnblogs.com/yinbiao/p/11598321.html
长度小于4的都可以直接写出来，长度大于等于4的，怎样都不能分割出1，令x=n%3, y=n/3：
4: 2x2, x=1, y=1
5: 2x3, x=2, y=1
6: 3x3, x=0, y=3
7: 2x2x3, x=1, y=2
8: 2x3x3, x=2, y=2
9: 3x3x3, x=0, y=3
10: 2x2x3x3, x=1, y=3
11: 2x3x3x3, x=2, y=3
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 1)return 0;  //长度为1的绳子，剪不了
        if(n == 2)return 1;  //长度为2的绳子，最大乘积为1
        if(n == 3)return 2;  //长度为3的绳子，最大乘积为2
        int x = n % 3, y = n / 3;
        if(x == 0)
        {
            //说明可以整除3
            return pow(3, y);  //返回3^y
        }
        if(x == 1)
        {
            return 2*2*pow(3, y-1);
        }
        if(x == 2)
        {
            return pow(2, x-1)*pow(3, y);
        }
        return 0;
    }
};
```