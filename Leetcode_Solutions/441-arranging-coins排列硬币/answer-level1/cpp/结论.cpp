### 解题思路
快乐的一行代码

### 代码

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(((sqrt(1+8*(long long)n)-1)/2.0));
    }
};
```