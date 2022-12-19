### 解题思路
此处撰写解题思路
判断回文可以从中间开始判断，如果是奇数，两边扩散，如果是偶数，向前寻一位，两边扩散
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=0)
        return "";
        int maxs=1;
        string result="";
        result+=s[0];
        for(int i=1;i<s.size();i++)
        {
            //首先看看有没有可能作为中点回文，奇数
            int j=i-1;
            int k=i+1;
            while(j>=0 && k<s.size() && s[j]==s[k])
            {
                j--;
                k++;
            }
            if(maxs<k-j-1)
            {
                maxs=k-j-1;
                result=s.substr(j+1,maxs);
            }
            //然后来看看有没有成为偶数回文串的可能，偶数，取其为中间靠右的开始
            j=i-1;
            k=i;
             while(j>=0 && k<s.size() && s[j]==s[k])
            {
                j--;
                k++;
            }
            if(maxs<k-j-1)
            {
                maxs=k-j-1;
                result=s.substr(j+1,maxs);
            }
        }
        return result;
    }
};
```