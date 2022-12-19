### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string str="";
        if(s=="")return str;
        string space=" ";
        while(1)
        {
            if(s[0]==' ')s.erase(s.begin());
            if(s[s.length()-1]==' ')s.erase(s.begin()+s.length()-1);
            else break;
        }
        if(s=="")return str;
        int left=s.length()-1,right=s.length()-1;
        for(;right>=0;right--)
        {
            if(s[right]!=' ')
            {
                for(int j=right;j>=0;j--)
                {
                    if(s[j]!=' ')
                        left=j;
                    else break;
                }
                str.append(s.begin()+left,s.begin()+right+1);
                str.append(space);
                right=left-1;
            }
            
        }
        str.erase(str.length()-1);
        return str;
    }
};
```