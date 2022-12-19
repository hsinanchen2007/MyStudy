### 解题思路
1. 使用hash table

### 代码

```cpp
class Solution {
public:
    int findString(vector<string>& words, string s) {
      // hash table
      unordered_map<string, int> map;
      for(int i = 0; i < words.size() ; ++ i) {
          // 剪枝
        if(words[i] == "") continue;
        map[words[i]] = i;
      }

      // 查找
      auto iter = map.find(s);
      if(iter != map.end())
        return iter->second;

      return -1;

    }
};
```