![QQ图片20191125102637.png](https://pic.leetcode-cn.com/1d92ef014cb01ad7eb0fff50ce6cb238f330fccbf71e10e4ab3e1c3b61a6d400-QQ%E5%9B%BE%E7%89%8720191125102637.png)

```
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.length();
        string res(dominoes);
        int l=INT_MAX;
        int r=INT_MAX;
        for(int i=0;i<n;++i)
        {
            if(dominoes[i]=='.')
            {
                if(i>0&&dominoes[i-1]=='.')
                {
                    if(l<INT_MAX)++l;
                    if(r<INT_MAX)--r;
                }
                else
                {
                    l=1;
                    while(true)
                    {
                        if(i-l<0)
                        {
                            l=INT_MAX;
                            break;
                        }
                        if(dominoes[i-l]=='L')
                        {
                            l=INT_MAX;
                            break;
                        }
                        if(dominoes[i-l]=='R')
                        {
                            break;
                        }
                        ++l;
                    }

                    r=1;
                    while(true)
                    {
                        if(i+r>=n)
                        {
                            r=INT_MAX;
                            break;
                        }
                        if(dominoes[i+r]=='L')
                        {
                            break;
                        }
                        if(dominoes[i+r]=='R')
                        {
                            r=INT_MAX;
                            break;
                        }
                        ++r;
                    }
                }

                if(l>r)
                {
                    res[i]='L';
                }
                else if(l<r)
                {
                    res[i]='R';
                }

            }
        }
        return res;
    }
};
```
