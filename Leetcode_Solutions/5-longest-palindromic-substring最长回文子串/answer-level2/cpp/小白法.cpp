### 解题思路
遍历法：遍历对称轴。因为有回文就一定有对称轴，这个对称轴要么就是字符本身，要么就在两两字符之间。所以分成两种情况遍历。
本以为会超时，没想到效果还不错。
![1582198660(1).png](https://pic.leetcode-cn.com/0cdfad8aa4dbc8ca2c8ca71cb1b178cd54f6c2c059a3a6e966897a6cb42c31ab-1582198660\(1\).png)
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if (s=="")
        {return "";}
        int length=0;
        string result="";
        for(int i=0;i<s.size();i++)
        {
            int j = 0;
            while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j])
            {
                if(length<1+2*j)
                {
                    length = 1+2*j;
                    result = s.substr(i-j,length);
                }
                j++;
            }
        }
        for(int i=0;i<s.size()-1;i++)
        {
            int j = 0;
            while(i-j>=0&&i+j+1<s.size()&&s[i-j]==s[i+j+1])
            {
                if(length<(j+1)*2)
                {
                    length = 2*j+2;
                    result = s.substr(i-j,length);
                }
                j++;
            }
        }
        return result;
    }
};
```