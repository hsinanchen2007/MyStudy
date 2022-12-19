### 解题思路
此处撰写解题思路
本题的困难版本是 340. 至多包含 K 个不同字符的最长子串。
使用hashmap保存子串中已经存在的字符串，如果有重复的则滑动往前遍历。遍历完所有节点后，得到最长子串值。
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 || n == 1) {
            return n;
        }

        int max = 0;
        unordered_map<char, int> hash_map;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            if (hash_map.find(s[i]) != hash_map.end()) {
                i = hash_map[s[i]] + 1;
                hash_map.clear();
            }
            hash_map.insert(make_pair(s[i], i));
            temp = hash_map.size();
            if (temp > max) {
                max = temp;
            }
        }
        return max;
    }
};
```
