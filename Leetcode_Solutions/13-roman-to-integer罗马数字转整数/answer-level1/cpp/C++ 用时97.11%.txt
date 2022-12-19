### 解题思路
遍历string,switch筛选情况

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int len = s.size(),num = 0;
        for(int i = 0;i<len;i++){
            switch(s[i]){
                case 'I':
                    if(s[i+1]=='V'){
                        num+=4;
                        i++;
                    }
                    else if(s[i+1]=='X'){
                        num+=9;
                        i++;
                    }
                    else num++;
                    break;

                case 'X':
                    if(s[i+1]=='L'){
                        num+=40;
                        i++;
                    }
                    else if(s[i+1]=='C'){
                        num+=90;
                        i++;
                    }
                    else num+=10;
                    break;

                case 'C':
                    if(s[i+1]=='D'){
                        num+=400;
                        i++;
                    }
                    else if(s[i+1]=='M'){
                        num+=900;
                        i++;
                    }
                    else num+=100;
                    break;

                case 'V':num+=5;break;
                case 'L':num+=50;break;
                case 'D':num+=500;break;
                case 'M':num+=1000;break;
            }
        }
        return num;
    }
};
```