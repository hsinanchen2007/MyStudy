### 解题思路
一、当前不为右括号时，就将当前字符加入到临时字符串
二、当前为右括号时，就去临时字符串中寻找有没有左括号，若有左括号则匹配左括号，若没有左括号就匹配*
三、对临时字符串中的左括号和*按顺序进行判断是否满足括号匹配

### 代码

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        string temp;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='*'||s[i]=='(')
                temp+=s[i];
            else
            {
                if(temp.size()==0)
                return 0;
                else
                {
                    int flag=0;
                    for(int j=temp.size()-1;j>=0;--j)
                    {
                        if(temp[j]=='(')
                        {
                            temp=temp.substr(0,j)+temp.substr(j+1);
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    temp=temp.substr(0,temp.size()-1);
                }
            }
        }
        int countz=0;
        for(int i=0;i<temp.size();++i)
        {
            if(temp[i]=='(')
            countz++;
            else
            {
                if(countz>0)
                --countz;
            }
        }
        if(countz<=0)
        return 1;
        else
        return 0;
    }
};
```