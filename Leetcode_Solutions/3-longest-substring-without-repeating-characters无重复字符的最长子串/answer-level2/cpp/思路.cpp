### 解题思路
滑动窗口 + map
优化后的效率更高

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.size() == 0 || s.size() == 1) return s.size();
      map<char, int> maps;
      int res = 0;
      for(int i = 0, j = 0; j < s.size(); j++){
        if(maps.find(s[j]) != maps.end()){
          i = max(i, maps[s[j]]);
        }
        res = max(j - i + 1, res);
        maps[s[j]] = j + 1;
      }
      return res;
    }
};
```