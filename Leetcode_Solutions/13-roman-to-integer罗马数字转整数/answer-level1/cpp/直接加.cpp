### 解题思路
根据情形直接无脑加，如果大数的前一位有小数，就减去小数两倍~

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        for(int i=0;i<s.size();i++){
            switch (s[i]){
                case 'I':
                    num+=1;break;
                case 'V':
                    num+=5;
                    if(i-1>=0&&s[i-1]=='I') num-=2;
                    break;
                case 'X':
                    num+=10;
                    if(i-1>=0&&s[i-1]=='I') num-=2;
                    break;
                case 'L':
                    num+=50;
                    if(i-1>=0&&s[i-1]=='X') num-=20;
                    break;
                case 'C':
                    num+=100;
                    if(i-1>=0&&s[i-1]=='X') num-=20;
                    break;
                case 'D':
                    num+=500;
                    if(i-1>=0&&s[i-1]=='C') num-=200;
                    break;
                case 'M':
                    num+=1000;
                    if(i-1>=0&&s[i-1]=='C') num-=200;
                    break;
                default: break;
            }
        }
        return num;
    }
};
```