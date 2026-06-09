### 解题思路
暴力解法 c++

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        if(s.size()==0)return 0;
        int i=0;
        int sum=0;
        while(s[i]!='\0'){
            switch (s[i]){
                case 'I':
                    if(s[i+1]=='V'){sum+=4;i=i+2;break;}
                    else if(s[i+1]=='X'){sum+=9;i=i+2;break;}
                    else {sum+=1;i=i+1;break;}
                case'V':
                    sum+=5;
                    i++;
                    break;
                case 'X':
                    if(s[i+1]=='L'){sum+=40;i=i+2;break;}
                    else if(s[i+1]=='C'){sum+=90;i=i+2;break;}
                    else {sum+=10;i=i+1;break;}
                case 'L':
                    sum+=50;
                    i++;
                    break;
                case 'C':
                    if(s[i+1]=='D'){sum+=400;i=i+2;break;}
                    else if(s[i+1]=='M'){sum+=900;i=i+2;break;}
                    else{sum+=100;i=i+1;break;}
                case 'D':
                    sum+=500;
                    i++;break;
                case 'M':
                    sum+=1000;
                    i++;break;
                default:break;

            }
        }
        if(sum>=1 && sum<=3999)return sum;
        else return 0;

        
    }
};
```