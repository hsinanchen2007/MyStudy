### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/f0629f3ffd070b64d449111f7e6ecdd0231775773e0bc9e810c59a17866965a5-image.png)

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int q) {
        long n=q;
        if(n<0){x=1/x;n=-n;}
        double res=1;
        while(n)
        {
            if(n&1) res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
};
```