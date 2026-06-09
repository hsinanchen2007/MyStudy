### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0, right = 0;
        map<char, int> table;
        int max_len = 0;

        for (; right < s.size(); right++) {
            if (table.find(s[right]) != table.end())
                table[s[right]]++;
            else
                table[s[right]] = 1;

            if (table.size() == k) {
                max_len = right + 1;
                break;
            }
        }

        if (table.size() < k)
            return right;

        while (++right < s.size()) {
            if (table.find(s[right]) == table.end()) {
                while (table.size() == k) {
                    table[s[left]]--;
                    if (table[s[left]] == 0)
                        table.erase(s[left]);
                    left++;
                }
                table[s[right]] = 1;
            } else
                table[s[right]]++;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
```