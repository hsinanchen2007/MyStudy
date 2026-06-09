### 解题思路
本来最初构思的时候，是最低端的方法，用count和pos两个数据，直接逐个判别错误情况，但是发现可能考虑不全面，也不是中等题的画风。看了一下大佬有用正则表达式做的，但是C没有哈哈，我也没有太接触过。看到有个大佬把有限状态机和此题联系起来，就去网上查了相关的资料，发现有限状态机这种编程思路是凝集了低端方法的精华：按照系统运行规律，把系统的可能出现的状态罗列出来，通过FSM的逻辑，可以将字符串的输入顺序归纳成一个有限状态图，当前状态和当前字符串决定了下一个状态，通过这样，列举正确的逻辑比错误的逻辑工作量少，当然网上有SWITCH CASE写法的，可能更为直观。

### 代码

```c

bool isNumber(char* s){
int i=0,state=0;
int flag=1;
while(s[i]!='\0'){
    if(s[i]==32){
       if(state==4||state==2||(state==3&&flag==1)) state=8;
       if(state==7) state=9;
       if (state!=0&&state!=8&&state!=9) return 0;
    }
    else if('0' <= s[i] && s[i] <= '9')
     {
         if(state==3&&flag==0) flag=1;
         if (state <= 2) {
                state = 2;
                
             } else if (state <= 4) {
                state = 4;
             }
             else if (state <= 7) {
                state = 7;
            }
            else return 0;
     }
     else if (s[i] == '+' || s[i] == '-')
     {
            if (state == 0 || state == 5) {
                state++;
            } else {
                return 0;
            }
     }
     else if (s[i] == '.') 
     {
         if (state==0||state==1) flag=0;
          if (state < 3) {
                state = 3;
             } 
             else {
                return 0;
            }
     }
     else if (s[i] == 'e' || s[i] == 'E'){
         if (state >= 2&&state <= 4) {
                state = 5;
             } 
             else {
                return 0;
            }
     }
     else return 0;
     i++;    
}
return (state==2||(flag&&(state==3||state==7))||state==4||state==8||state==9);
}
```