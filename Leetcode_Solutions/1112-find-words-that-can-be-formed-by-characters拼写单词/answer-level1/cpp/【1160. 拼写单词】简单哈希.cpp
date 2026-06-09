## 思路
将字母表放入哈希表中，因为都为小写字母，所有使用数组模拟哈希表，然后对字符串数组的每个单词判断是否在字母表中，如果在则加上长度。

### 代码
时间复杂度：O(n^2)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> hash(26);
        int res = 0;
        for (char c : chars) {
            ++hash[c - 'a'];
        }
        for (string s : words) {
            vector<int> hash_copy(hash);
            int i;
            for (i = 0; i < s.size(); ++i) {
                if (hash_copy[s[i] - 'a'] == 0) break;
                --hash_copy[s[i] - 'a'];
            }
            if (i == s.size()) res += s.size();
        }
        return res;
    }
};
```