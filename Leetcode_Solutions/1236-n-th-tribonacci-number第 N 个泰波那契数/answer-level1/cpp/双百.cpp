### 解题思路
- 没递归，没动态规划

### 代码

```cpp
class Solution {
public:
    int tribonacci(int n) {
      if(n == 0) return 0;
      if(n <= 2) return 1;
      int a0 = 0;
      int a1 = 1;
      int a2 = 1;
      int ans =0;

      for(int i = 3; i <= n; ++i) {
        ans = a0 + a1 + a2;
        a0 = a1;
        a1 = a2;
        a2 = ans;
      }
      return ans;
    }
};
```