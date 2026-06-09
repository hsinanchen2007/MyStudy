### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int start=0,end=0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            for(int left = i, right = i;left >= 0 && right < s.length() ; left -- , right ++)
            {
                if(s[left] != s[right])
                    break;
                if((right - left + 1) > (end - start + 1))
                {
                    start = left;
                    end = right;
                }
            }
            for(int left = i,right = i + 1;left >= 0 && right < s.length();left--,right ++)
            {
                if(s[left] != s[right])
                    break;
                if((right - left + 1) > (end - start + 1))
                {
                    start = left;
                    end = right;
                }
            }
        }
        return s.substr(start,end - start + 1);
    }
};
```