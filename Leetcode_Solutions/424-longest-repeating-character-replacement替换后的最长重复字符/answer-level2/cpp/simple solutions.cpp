### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

  int characterReplacement(string s, int k) {
    int res = 0, maxCnt = 0, start = 0;
    vector<int> counts(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      maxCnt = max(maxCnt, ++counts[s[i] - 'A']);
      while (i - start + 1 - maxCnt > k) {
        --counts[s[start] - 'A'];
        ++start;
      }
      res = max(res, i - start + 1);
    }
    return res;
  }

};
```