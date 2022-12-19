1. 本质是快慢指针
2. 遍历字符串，快指针向前，并在ch_map记录遇到重复字符s[i]后的 “下一个位置”
3. 若在快慢指针之间遇到相同的字符(if处的条件判断)，慢指针指向遇到重复字符的下一个位置(ch_map中的值)
4. 用256长度的数组做char和char在string中位置的映射

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {    
        int ch_map[256] = {0};
        int fast_ptr = 0, slow_ptr = 0, max_len = 0;   
        for (int &i = fast_ptr; i < s.size(); ++i)
        {
            if (ch_map[s[i]] == 0 || ch_map[s[i]] < slow_ptr)
            {
                max_len = max( max_len, i - slow_ptr + 1 );
            }
            else slow_ptr = ch_map[s[i]];
            ch_map[s[i]] = i + 1;
        }
        return max_len;

    }
};
```