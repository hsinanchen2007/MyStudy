### 缺陷
Line 16: Char 18: runtime error: index 50 out of bounds for type 'char [50]' (solution.c)
没有给栈分配动态空间，导致最后一个测试案例不通过（最终暴力修改：char Stack[10000];），汗颜……
然后整个代码块写得啰哩啰嗦，逻辑上也不是很缜密。
注释写得比较简陋……

### 代码

```c
bool isValid(char * s){
    char Stack[10000];
    if(s==NULL || s[0]=='\0') return 1;

    //计算字符串s长度num；当num为奇数时return 0
    int num=0;
    char *p=s;
    while(p!=NULL && *p!='\0'){
        num++;
        p++;
    }if(num%2==1) return 0;

    int top=-1;
    while(s!=NULL && *s != '\0'){
        if(*s=='(' || *s=='[' || *s=='{'){
            Stack[++top]=*s;
            s++;
        }
        else{
            if(top==-1){ //栈为空（此时top==-1）
                return 0;
            }
            if(*s==')' && Stack[top]!='('){
                return 0;
            }
            else if(*s==']' && Stack[top]!='['){
                return 0;
            }
            else if(*s=='}' && Stack[top]!='{'){
                return 0;
            }
            else{
                top--;
                s++;
            }
        }
    }
    if(top!=-1) return 0; //栈不为空，无效
    return 1;
}
```