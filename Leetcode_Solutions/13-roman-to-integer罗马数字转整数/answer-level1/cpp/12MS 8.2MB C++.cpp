12MS 8.2MB C++ 
首先存储字符和对应值，每次循环只负责本次当前值的操作
找到当前字符对应的值，再找下一个字符对应的值，
如果 当前字符值大于下一字符值，加上当前字符值
如果 当前字符值小于下一字符值，减去当前字符值
处理最后一个字符
the end。
```
class Solution {
public:
    int romanToInt(string s) {
        int x=0;
        char a[7]{'M','D','C','L','X','V','I'};
        int c[7]{1000,500,100,50,10,5,1};
        for(int i=0;i<s.size()-1;i++)
        {
            int k=0;
            int n=0;
            while(s[i]!=a[k]) k++;
            while(s[i+1]!=a[n]) n++;
            if(k<=n)
                x=x+c[k];
            else
                x=x-c[k];
        }
        int k=0;
        while(s[s.size()-1]!=a[k]) k++;
        x=x+c[k];
        return x;
    }
};
```




