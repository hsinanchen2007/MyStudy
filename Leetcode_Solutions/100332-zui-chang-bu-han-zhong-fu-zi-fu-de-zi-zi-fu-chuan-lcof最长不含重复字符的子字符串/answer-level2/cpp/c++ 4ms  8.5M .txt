### 解题思路
此处撰写解题思路
窗口滑动  窗口范围内只保留现在还剩余不重复的字符串

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int cur=0,max=1;
        for(int i=0;i<s.length();i++)
        {
            for(int j = cur;j<i;j++)
            {
                if(s.at(j) == s.at(i))
                {
                    max = max>(i-cur)?max:(i-cur);
                    cur = j+1;
                    break;
                }
            }
        }
        max = max>(s.length()-cur)?max:(s.length()-cur);
        return max;
    }
};
```