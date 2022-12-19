## 思路
### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) {
            return 0;
        }
        return helper(s, k, 0, s.size());
    }
    int helper(string &s, int k, int start, int end) {
        vector<int> count(26, 0);
        //在start和end范围内统计每个字母出现次数
        for (int i = start; i < end; ++i) {
            ++count[s[i] - 'a'];
        }
        int res = 0;
        for (int i = start; i < end;) {         
            //找第一个字母出现次数大于等于k   
            while (i < end && count[s[i] - 'a'] < k) {
                ++i;
            }
            if (i == end) {
                break;
            }
            int j = i;
            //找第一个字母出现次数小于k
            while (j < end && count[s[j] - 'a'] >= k) {
                ++j;
            }
            //找到一个子串满足条件
            if (i == start && j == end) {
                return end - start;
            }             
            res = max(res, helper(s, k, i, j));
            i = j + 1;
        }
        return res;
    }
};
```
