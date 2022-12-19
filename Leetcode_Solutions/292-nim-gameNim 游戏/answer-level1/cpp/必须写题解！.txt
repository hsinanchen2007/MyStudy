### 解题思路
有史以来最简单的一道题

### 代码

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return (n%4==0)?0:1;
    }
};
```