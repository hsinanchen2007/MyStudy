### 解题思路
公式

### 代码

```cpp
class Solution {
public:
    int arrangeCoins(int n) {  
        return floor(sqrt(0.5*n+1/16.0)*2.0-0.5);
    }
};
```