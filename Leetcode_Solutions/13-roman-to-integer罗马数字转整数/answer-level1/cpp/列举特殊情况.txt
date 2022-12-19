### 解题思路
（1）用length返回长度，把所有特殊情况列出来即可以。
（2）执行用时可以继续改进。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int x=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I'&&s[i+1]=='V')
            {
                x+=4;
                i++;
                continue;
            }
             if(s[i]=='I'&&s[i+1]=='X')
            {
                x+=9;
                i++;
                continue;
            }
               if(s[i]=='X'&&s[i+1]=='L')
            {
                x+=40;
                i++;
                continue;
            }
               if(s[i]=='X'&&s[i+1]=='C')
            {
                x+=90;
                i++;
                 continue;
            }
               if(s[i]=='C'&&s[i+1]=='D')
            {
                x+=400;
                i++;
                continue;
            }
               if(s[i]=='C'&&s[i+1]=='M')
            {
                x+=900;
                i++;
                continue;
            }
            if(s[i]=='I') x+=1;
            if(s[i]=='V') x+=5;
            if(s[i]=='X') x+=10;
            if(s[i]=='L') x+=50;
            if(s[i]=='C') x+=100;
            if(s[i]=='D') x+=500;
            if(s[i]=='M') x+=1000;
        }
        return x;
    }
};
```