```
class Solution {
public:
    bool isright(int m,string s)
    {
        int n=s.size()/m;
        string temp=s.substr(0,m);
        for(int i=1;i<n;i++)
        {
            if(temp!=s.substr(i*m,m))
                return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int len=min(str1.size(),str2.size());
        int m=str1.size();
        int n=str2.size();
        for(int i=len;i>=1;i--)
        {
            if(m%i==0&&n%i==0)
            {
                if(isright(i,str1)&&isright(i,str1)&&str1.substr(0,i)==str2.substr(0,i))
                    return str1.substr(0,i);
            }
        }
        return "";
    }
};
```
![@GWZPO76DKCK`\]~@C@9W4YS.png](https://pic.leetcode-cn.com/f97c2c90aca482d6cfa8645363ca4fb35f07a607e76829f2b559768c9d8e926c-@GWZPO76DKCK%60%5D~@C@9W4YS.png)