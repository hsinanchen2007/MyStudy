pow(x,y)函数的意思就是求x的y次方。在头文件<math.h>中
后面就是利用26进制的与10进制之间的转换

```
class Solution {
public:
    int titleToNumber(string s) 
    {
        int len=s.size();
        int ans=0;
        for(int i=0;i<len;i++)
        {
            ans+=(s[i]-'A'+1)*pow(26,len-(i+1));
        }
        return ans;
    }
};
```
