暴力。。。!_!
不能跟大佬比。
![image.png](https://pic.leetcode-cn.com/34157d99517b87e49d58c62414c39c1979a99114423ae383a572c52b4c56506d-image.png)
测试时间不稳定 0-8ms 都有
```c++ []
class Solution {
public:
    bool isNumber(string s) {
        int n=s.length();
        int i=0;
        int e=0;
        int f=0;
        int d=0;
        int num=0;
        int k=0;
        while(s[k]==' ')
            k++;
        int j=n-1;
        while(s[j]==' ')
            j--;
        n=j+1;
        if(k>=n)
            return false;
        for(i=k;i<n;i++)
        {
            
            if('0'<=s[i]&&s[i]<='9')
            {
                continue;
            }
            if(s[i]=='e'&&e==0&&i>k&&i<n-1)
            {
                if('0'>s[i+1]||s[i+1]>'9')
                {
                    
                    if(s[i+1]!='-'&&s[i+1]!='+')
                        return false;
                }
                if(('0'<=s[i-1]&&s[i-1]<='9')||s[i-1]=='.')
                {
                    e++;
                    //cout<<"e";
                    f=0;
                    continue;
                }
            }
            if((s[i]=='-'||s[i]=='+')&&f==0)
            {
                if(i==n-1)
                    return false;
                if(i>k)
                {
                    
                        if(s[i-1]!='e')
                            return false;                   
                }
                f++;
                continue;
            }
            if(s[i]=='.'&&e==0&&d==0)
            {
                if(i==k)
                {
                    if(i==n-1)
                        return false;
                    else
                    {
                        if('0'>s[i+1]||s[i+1]>'9')
                            return false;
                    }
                }
                else
                {
                    if('0'>s[i-1]||s[i-1]>'9')
                    {
                        if(i==n-1)
                            return false;
                        else if('0'>s[i+1]||s[i+1]>'9')
                            return false;
                    }
                }
                d=1;
                //cout<<"d";
                continue;
            }
            return false;
        }
        
        return true;
    }
};
```
