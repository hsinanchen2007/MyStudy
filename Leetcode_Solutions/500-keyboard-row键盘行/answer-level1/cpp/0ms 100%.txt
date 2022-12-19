### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
      if (words.empty()) return {};
      unordered_map<char, int> m = {
          {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1},
          {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2},
          {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3}
      };

      vector<string> ans;
      for (const auto &word: words) {
        unordered_map<int, int> count;
        for (const auto &c: word) {
          // 属于同一组的+1
          count[m[tolower(c)]]++;
        }
        if (count.size() == 1) {
          ans.push_back(word);
        }
      }
      return ans;
    }
};
```