### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
      int val = 0;
      while (x) {
          if (val < INT_MIN / 10 || val > INT_MAX / 10) return 0;
          val *= 10;
          val += x % 10;
          x = x / 10;
      } 
      return val;
    }
};
```