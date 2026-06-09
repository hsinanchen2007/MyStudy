### 解题思路
执行用时 :
20 ms
, 在所有 C++ 提交中击败了
89.52%
的用户
内存消耗 :
9 MB
, 在所有 C++ 提交中击败了
78.66%
的用户

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) { 
        int l=s.size();
        if(l==0)    return "";
        int i,start=0,end=0,len1,len2,len3,left,right;
        for(i=0;i<l;i++)
        {
            left=i,right=i;
            while(left>=0&&right<=l-1&&s[left]==s[right])
            {
                left--;
                right++;
            }
            len1=right-left-1;
            left=i,right=i+1;
            while(left>=0&&right<=l-1&&s[left]==s[right])
            {
                left--;
                right++;
            }
            len2=right-left-1;
            len3=max(len1,len2);
            if(len3>end-start+1)
            {          
                    start=i-((len3+1)/2)+1;
                    end=i+(len3/2);
            }
        }
        return s.substr(start,end-start+1);
    }
};
```