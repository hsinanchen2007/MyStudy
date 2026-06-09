### 解题思路

没得思路。看着自己写的像个鬼。但是跑过了，测试的案例给我整吐了。
提交了五遍才过。
继续学习，加油，奥里给！

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        if(len == 0) return 0;
        int Anum = 0;
        int Znum = 0;
        bool blNum = true;
        double reNum = 0;
        for(int i = 0; i < len; i++){
            if( ('0'<= str[i] && str[i] <= '9') ||  str[i] == '-'  || str[i] == '+'  || str[i] == ' ')
            {
                if(str[i] == '-' || str[i] == '+') Anum++;
                if(Anum > 1 && reNum == 0) break;
                if(str[i] == '0') Znum++;
                if(str[i] == '-' && reNum == 0 && Znum == 0) {
                    blNum = false;
                    continue;
                }else if((str[i] == '+' && reNum != 0) || (str[i] == ' ' && reNum != 0) || (str[i] == '-' && reNum != 0 ) || (str[i] == ' ' && reNum == 0 && Anum != 0) || ((str[i] == '+' || str[i] == '-') && Znum != 0) || (str[i] == ' ' && Znum != 0) ) break;
                if('0'<= str[i] && str[i] <= '9'){
                    reNum = reNum*10 + str[i] - '0';
                }
            }else break;
        }
        if(!blNum){ 
            if(-reNum < INT_MIN) return INT_MIN;
            else return -reNum;
        }else{
            if(reNum > INT_MAX) return INT_MAX;
            else return reNum;
        }
        return 0;
    }
};
```