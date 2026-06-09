### 解题思路
主要是用了stol函数
### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        if(str=="") return 0;
        int n=str.size();
        long ans;
        string res;
        int i=0;
        for(;i<n;++i)
            if(str[i]!=' ') break;
        if(str[i]=='+'||str[i]=='-'||(str[i]>='0'&&str[i]<='9'))
        {
            if(str[i]=='+'||str[i]=='-')
            {
                res+=str[i];
                ++i;
            }
            for(;i<n;++i)
            {
                if(str[i]!='0')
                {
                    for(;i<n;++i)
                    {
                        if(str[i]>='0'&&str[i]<='9')
                        {
                            res+=str[i];
                            if(res.size()>11)
                            break;
                        }
                        else break;
                    }
                    break;
                }
            }
            if(res=="+"||res=="-"||res=="") return 0;
            ans=stol(res);
            if(ans<INT_MIN) ans=INT_MIN;
            if(ans>INT_MAX) ans=INT_MAX;
            return ans;
        }
        else return 0;
    }
};
```