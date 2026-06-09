### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int addDigits(int num) {
        int a;
        a=(num-1)%9+1;
        return a;
    }
};
```