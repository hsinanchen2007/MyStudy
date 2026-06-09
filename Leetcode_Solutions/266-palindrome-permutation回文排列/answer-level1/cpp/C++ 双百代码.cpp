时间复杂度 O(n)
空间复杂度 O(1)

```
class Solution {
public:
    bool canPermutePalindrome(string s) {
      int array[256] = {0};
      for (auto c: s) array[c]++;
      int odd = 0;
      for (auto i: array) {
        if (i % 2 != 0) {
          odd++;
          if (odd > 1) return false;
        }
      }
      return true;
    }
};
```
