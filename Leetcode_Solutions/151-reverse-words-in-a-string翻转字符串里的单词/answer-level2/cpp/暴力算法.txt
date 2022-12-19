### 解题思路
找到所有单词，倒序加进需要返回的字符串。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        
        if(s.empty() || count(s.begin(),s.end(),' ')==s.size())
        {
            return "";
        }
        
        string temp;
        string str="";
        int i,j;
        
        for(i=0;i<s.size();i++)
        {
            if((i==0 && s[i]!=' ') || (s[i]!=' ' && s[i-1]==' '))
            {
                temp="";
                for(j=i;j<s.size();j++)
                {
                    if((j==s.size()-1 && s[j]!=' ') || (s[j]!=' ' && s[j+1]==' '))
                    {
                        temp.append(s.begin()+i,s.begin()+j+1);
                        str=" "+temp+str;
                        break;
                    }
                }
            }
        }
        
        str.erase(str.begin());
        
        return str;

    }
};
```