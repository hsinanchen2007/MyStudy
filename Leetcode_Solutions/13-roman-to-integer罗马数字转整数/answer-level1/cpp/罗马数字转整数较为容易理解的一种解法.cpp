### 解题思路
    遍历整个字符串：
    遇到I的话，分为3种情况，4、9、其他。判断I后面的字符，如果是V，则为4；如果是X，为9；不为V或X，则为其他。4或9的情况，就将4或9加上Sum,然后遍历到的位置加一（跳过V或X）；其他的情况就看有多少个I就加多少个1；
    X和C也同理。
    遇到除了X V I的符号就无脑加对应的值就好了

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        string single;
        int Sum=0;
        for (int i=0;i<s.length();i++)
        {
            single=s.substr(i,1);
            if(single=="I")
            {
                if(s.substr(i+1,1)=="V")
                {
                    Sum+=4;
                    i++;
                }
                else if(s.substr(i+1,1)=="X")
                {
                    Sum+=9;
                    i++;
                }
                else 
                {
                    Sum+=1;
                }
            }
            else if(single=="X")
            {
                if(s.substr(i+1,1)=="L")
                {
                    Sum+=40;
                    i++;
                }
                else if(s.substr(i+1,1)=="C")
                {
                    Sum+=90;
                    i++;
                }
                else 
                {
                    Sum+=10;
                }
            }
            else if (single=="C")
            {
                if(s.substr(i+1,1)=="D")
                {
                    Sum+=400;
                    i++;
                }
                else if(s.substr(i+1,1)=="M")
                {
                    Sum+=900;
                    i++;
                }
                else 
                {
                    Sum+=100;
                }
            }
            else if (single=="V")
            {
                Sum+=5;
            }
            else if (single=="L")
            {
                Sum+=50;
            }
            else if (single=="D")
            {
                Sum+=500;
            }
            else if (single=="M")
            {
                Sum+=1000;
            }
        }
        return Sum;
    }
};
```