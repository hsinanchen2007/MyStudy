### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    string compare(string s1,string s2)
    {
        string r = "";
        int n = min(s1.size(),s2.size());
        if(n==0)
        return "";
         for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[i])
            r += s1[i];
            else
            break;
        }
        return r;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string r = "";
        int n = strs.size();
        if(n==0)
        return r;
        r=strs[0];
        for(int i=0;i<n;i++)
        {
           r=compare(strs[i],r);
        }
        return r ;
    }
   
};
```