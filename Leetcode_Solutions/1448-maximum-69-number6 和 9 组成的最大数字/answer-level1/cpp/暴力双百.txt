### 解题思路
最大不过10000直接拆分判断

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        int a = num / 1000, b = (num % 1000) / 100, c = (num % 100) / 10, d = num % 10;
        if (a == 6)     {return num+3000;}
        else if (b == 6){return num+300;}
        else if (c == 6){return num+30;}
        else if (d == 6){return num+3;}
        else            {return num;}
    }
};
```