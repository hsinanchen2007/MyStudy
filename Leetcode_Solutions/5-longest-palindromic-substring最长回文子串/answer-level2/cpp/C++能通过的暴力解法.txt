![image.png](https://pic.leetcode-cn.com/e2de295e1ade589576f35ef3a5e53902836e41c1f05448f05d6e7e5a10a34556-image.png)

```
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        int maxl=0;  //l用来记录当前最长的回文子串
        if (s.size()==0) return res;
        if(s.size()==1)return s;
        res=s[0];//返回子串初始化为第一个元素
       
        for (int i = 0; i<n-1; i++)
        {
            for (int j=n-1;j>i;j--)
            {
                if((s[i] == s[j]))
                {
                    int p1=i,p2=j;
                    while(p1<p2&&s[p1]==s[p2])
                    {
                     ++p1,--p2;
                    }
                    if((p1==p2||p2==p1-1)&&j-i+1>maxl)
                    {
                        maxl=j-i+1;
                        res=s.substr(i,maxl);
                    }
                    
                }
                if (maxl==n)
                return res;
            }
        }
        return res;
    }
};

```
