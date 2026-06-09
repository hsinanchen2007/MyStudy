### 解题思路
1.建立键值对
2.取当前字母，再查看下一个字母，看两个组合起来是否为特殊情况
### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int num=0;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='I')
            {
                if(s[i+1]=='V'||s[i+1]=='X')
                {
                    num=num+(m[s[i+1]]-m[s[i]]);
                    i=i+2;
                }
                else
                {
                    num=num+m[s[i]];
                    i++;
                }
            }
            else if(s[i]=='X')
            {
                if(s[i+1]=='L'||s[i+1]=='C')
                {
                   num=num+(m[s[i+1]]-m[s[i]]);
                    i=i+2;
                }
                else
                {
                    num=num+m[s[i]];
                    i++; 
                }
            }
            else if(s[i]=='C')
            {
                if(s[i+1]=='D'||s[i+1]=='M')
                {
                   num=num+(m[s[i+1]]-m[s[i]]);
                    i=i+2;
                }
                else
                {
                    num=num+m[s[i]];
                    i++; 
                }
            }
            else
            {
                num=num+m[s[i]];
                i++;
            }
        }
        return num;
    }
};
```