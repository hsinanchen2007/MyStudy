这个方法比较笨，循环除2，看余数，直到最后结果n=1时，说明是2的幂，否则不是。看题解用的多是位计算

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        bool flag=true;
        while(n%2==0)
        {
           n=n/2;
        }
        if(n==1)
        {return flag;}
        else return false;


    }
};
```