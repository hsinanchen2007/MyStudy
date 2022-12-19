### 解题思路
此处撰写解题思路
滑窗法：用head和cursor两个指针来定位。当从head到cursor之间出现了重复，记录此时长度，将head更新到第一个重复字母后面一个的位置。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cursor,j,flag, res;
        int maxlength = 0;
        int length = 0;
        int head = 0;
        if(s.empty()) return 0;
        for(cursor = 0; cursor < s.size(); cursor++)
        {
            flag = 0;
            for(j = head; j<cursor;j++)
            {
                if(s[cursor]==s[j]&&cursor!=j)
                {
                    flag = 1; 
                    res = j;
                    break;
                }                    
            }
            if(flag) head = res+1;
            else length = cursor-head+1;
            if(length>=maxlength) maxlength = length;
        }
        return maxlength;
    }
};
```

