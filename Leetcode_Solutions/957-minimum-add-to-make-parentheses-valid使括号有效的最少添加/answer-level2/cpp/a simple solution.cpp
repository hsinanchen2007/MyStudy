### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
  int minAddToMakeValid(string S) {
    int l = 0;
    int r = 0;
    int ans = 0;
    for (int i = 0; i < S.length(); ++i) {
      S[i] == '(' ? ++l : ++r;
      if (r > l) l = r = 0, ++ans;
    }
    return ans + (l - r);
  }
};
```