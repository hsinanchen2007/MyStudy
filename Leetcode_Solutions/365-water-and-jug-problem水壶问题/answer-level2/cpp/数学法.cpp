### 解题思路
关键点：z能够除尽x和y的最大公约数，说明是可以返回true的。
其他的，就是注意边界情况。比如z是否等于0.z是否大于x+y,x、y、z是否小于0.

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
        if(x<0||y<0||z<0||z>x+y) return false;
        if(x==0||y==0) return x+y==z;
        if(z%gcd(x,y)==0)
        {
            return true;
        }
        return false;
    }
};
```
执行结果：通过 显示详情
执行用时 :
    0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
    7.3 MB, 在所有 C++ 提交中击败了100.00%的用户