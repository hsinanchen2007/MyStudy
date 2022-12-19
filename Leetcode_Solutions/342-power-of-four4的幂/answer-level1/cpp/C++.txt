### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num &(num-1)) == 0 && (num % 3 == 1);
    }
};
```