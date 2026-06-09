### 解题思路
一行代码出奇迹

### 代码

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return n==0?true :(n&1)^((n/2)&1)? hasAlternatingBits(n/2):false;
    }
};
```