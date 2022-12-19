思路：首先将sqrt范围限制在x/2+1以内，然后用牛顿迭代法逼近求解。
```
int mySqrt(int x) {
        long sqrt = x/2 + 1;
        while(sqrt * sqrt > x)
        {
            sqrt = (sqrt + x/sqrt)/2;
        }
        return sqrt;
    }
```
