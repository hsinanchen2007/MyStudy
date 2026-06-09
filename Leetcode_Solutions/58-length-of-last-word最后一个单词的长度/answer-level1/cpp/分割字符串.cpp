### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        //分割单词
        int len=s.size();
        string temp;
        vector<string> newString;
        for(int i=0;i<len;i++)
        {
            if(s[i]!=' ')
            {
                temp+=s[i];
                if(i==len-1)
                {
                  newString.push_back(temp);
                }
             
            }
            else 
            {
                if(temp.size()>0)
                {
                    newString.push_back(temp);
                temp="";
                }
            }
        }

if(newString.size()==0)
return 0;
else
        return newString[newString.size()-1].size();
    }
};
```