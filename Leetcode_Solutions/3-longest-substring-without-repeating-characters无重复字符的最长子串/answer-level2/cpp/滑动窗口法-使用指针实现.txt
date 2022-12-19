### 解题思路
使用的依旧是滑动窗口法，但是直接用一个变量来模拟指针，而不用容器，这样内存消耗会降到最小。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        size_t start_pos=0, end_pos=0;
        size_t pos;
        int max_cnt = 0;

        while(end_pos < s.size())
        {
            pos = s.find(s[end_pos], start_pos);
            if(pos < end_pos)
            {
                if(max_cnt < (end_pos - start_pos))
                    max_cnt = end_pos - start_pos;

                 start_pos = pos + 1;
            }

            end_pos++;
        }
        
        if(max_cnt < (end_pos - start_pos))
            max_cnt = end_pos - start_pos;

        if(start_pos == 0)
            max_cnt = s.size();

        return max_cnt;
    }
};
```