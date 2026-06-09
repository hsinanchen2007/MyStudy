### 解题思路
哈希表查找，两次遍历

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> mp;
        for (int i=0; i<s.size(); i++) {
            mp[s[i]] += 1;
        }
        for (int i=0; i<t.size(); i++) {
            if (mp.find(t[i])==mp.end() || mp[t[i]]==0) return false;
            else mp[t[i]]--;
        }
        return true;
    }
};
```