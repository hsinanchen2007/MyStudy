### 解题思路
此处撰写解题思路
数学解法，如果z是gcd(x,y)的倍数，则有解。
或者使用dfs，遍历每一种情况。x倒满，y倒满，x倒空，y倒空，x给y倒，y给x倒。
### 代码

```cpp
class Solution {
public:

    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(x == z || y == z) return true;
        return z % gcd(y,x) == 0;
    }
};
```