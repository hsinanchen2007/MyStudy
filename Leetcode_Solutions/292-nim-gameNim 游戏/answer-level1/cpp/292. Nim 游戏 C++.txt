### 解题思路
1.只要石头的数量不是4的倍数就一定可以赢。

### 代码

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};
```