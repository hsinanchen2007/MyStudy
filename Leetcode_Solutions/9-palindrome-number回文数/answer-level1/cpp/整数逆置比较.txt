### 解题思路
我的方法是将x逆置，得到cvs，然后与x与cvs比较，大小一样即符合，否则不符合。其中，逆置过程计算cvs会出现整数溢出情况，其实，溢出时就不符合条件了。当然，x<0时全部不符合。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int copy_x = x;
        int cvs = 0;
        for(; copy_x > 0;){
            if((INT_MAX - (copy_x % 10)) / 10 < cvs)
                return false;
            cvs = cvs * 10 + (copy_x % 10);
            copy_x = copy_x / 10;
        }
        if(cvs == x)
            return true;
        else
            return false;
    }
};
```