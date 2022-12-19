### 解题思路
这题目规则有点不符合常理。。

### 代码

```c


bool isValid(char * s){
    if(!*s) return true; 
    if(strlen(s)%2==1||*s==')'||*s==']'||*s=='}') return false; //特殊情况false
    char * temp=(char *)malloc(strlen(s)*sizeof(char)); //创栈
    int top=0;
    while(*s){
        switch(*s){
            case '(':
            case '[':
            case '{':{
                temp[top]=*s;
                s++;
                top++;
                break;    //进栈
            }
            case ')':{    //以下出栈
                if(temp[--top]!='(') return false;
                else {
                    s++;
                }
                break;
            }
            case ']':{
                if(temp[--top]!='[') return false;
                else {
                    s++;
                }
                break;
            }
            case '}':{
                if(temp[--top]!='{') return false;
                else {
                    s++;
                }
            }
        }
    }
    return !top?true:false;//最后判断栈是否为空
}
```