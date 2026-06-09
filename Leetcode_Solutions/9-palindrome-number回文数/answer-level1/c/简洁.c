### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
      int max = 0x7fffffff; // int最大值
      if (x < 0) return false;
      long ret = 0;
      int temp = x;
      for (; x; ret = ret*10 + x%10, x = x/10); // 翻转
      if (ret > max) return false;
      return (ret == temp) ? true : false;
    }
};
```