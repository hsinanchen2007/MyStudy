### 解题思路
使用switch语句来处理遍历过来的字符，对于已知的6种特殊情况进行具体处理；

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
            int i=0,res=0;  
            while(i<s.length())
            {
                switch(s[i])
                {
                    case 'I':
                        if(i+1<s.length()&&s[i+1]=='V')  //"IV"的处理
                            {res=res+4;i+=2;break;}
                        else if(i+1<s.length()&&s[i+1]=='X')  //IX的处理
                            {res+=9;i+=2;break;}
                        else {res+=1;i++;break;}   //单个I的处理   （下面几个分支类似）
                    
                    case 'V':
                        res+=5;i++;
                        break;
                    
                    case 'X':
                       if(i+1<s.length()&&s[i+1]=='L')
                            {res+=40;i+=2;break;}
                        else if(i+1<s.length()&&s[i+1]=='C')
                            {res+=90;i+=2;break;}
                        else {res+=10;i++;break;}
                    
                    case 'L':
                        res+=50;i++;
                        break;
                    
                    case 'C':
                        if(i+1<s.length()&&s[i+1]=='D')
                            {res+=400;i+=2;break;}
                        else if(i+1<s.length()&&s[i+1]=='M')
                            {res+=900;i+=2;break;}
                        else {res+=100;i++;break;}
                    
                    case 'D':
                        res+=500;i++;
                        break;

                    case 'M':
                        res+=1000;i++;
                        break;

                    

                }

            }
            return res;
    }
};
```