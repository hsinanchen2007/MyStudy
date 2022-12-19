### 解题思路
此处撰写解题思路
思路就是遇到needle首字母相同的部分，就判断一下。
### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int t=-1;
        int pd;
        int n=haystack.size();
        int m=needle.size();
        int zhizhen=0;
        if(needle=="")
         t=0;
        else if (m>n)
         t=-1;
        else
        {
             for(int i=0;i<n;i++)
             {
                 if(needle[0]==haystack[i])
                 {
                     pd=1;
                       for(int j=0;j<m;j++)
                       {
                        if(i+m<=n)
                       {
                           if(needle[j]!=haystack[i+j])
                           {
                               pd=0;
                               break;
                           }  
                       }
                       else  {pd=0;break;}
                       }
                    if(pd==1)
                    {
                        t=i;
                        break;
                    }
                    else t=-1;
                 }     
             }
        }
        return t;
    }
};
```