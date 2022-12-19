### 解题思路
p1,p2指向末尾，直到重合。
将‘ ’改为%20，增加了字符串长度，因此此方法要记得对s进行扩展，否则会出现溢出的现象。

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        if(s.size()==0) return "";
        
        int n=s.size();
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ') 
            m++;//有m个空格
        }
        int p1=n-1;
        int p2=n-1+m*2;
        string temp(m*2,' ');
        s=s+temp;
        while (p1!=p2)
        {
            for(int i=0;i<n;i++)
            {
                if(s[p1]!=' ')
                {
                    s[p2]=s[p1];
                    p1--;
                    p2--;
                }
                else//' '
                {
                    s[p2]='0';
                    p2--;
                    s[p2]='2';
                    p2--;
                    s[p2]='%';
                    p2--;
                    p1--;
                }
            }

        }
return s;
    }
};
```