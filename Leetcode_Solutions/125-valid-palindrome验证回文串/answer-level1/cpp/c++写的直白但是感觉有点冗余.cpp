### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        if (s.size()<2)
        {
            return true;
        }
        while(i<j)
        {
            if((s[i]==s[j])||(((s[i]-s[j]==32)||(s[j]-s[i]==32))&&(s[i]>='A'&&s[j]>='A')))
            {
                i++;
                j--;
            }
            else if((!(s[i]>='A'&&s[i]<='Z'))&&(!(s[i]>='a'&&s[i]<='z'))&&(!(s[i]>='0'&&s[i]<='9')))
            {
                i++;
            }
            else if((!(s[j]>='A'&&s[j]<='Z'))&&(!(s[j]>='a'&&s[j]<='z'))&&(!(s[j]>='0'&&s[j]<='9')))
            {
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
```