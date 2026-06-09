```
class Solution {
public:
    bool canPermutePalindrome(string s) {
      int array[256] = {0}, res = 0;
      for (auto c: s) {
        if (++array[c] % 2) res++;
        else res--;
      }
      return res < 2;
    }
};
```
