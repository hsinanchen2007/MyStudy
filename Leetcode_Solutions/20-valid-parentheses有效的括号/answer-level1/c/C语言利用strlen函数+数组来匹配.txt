### 解题思路
参考了一些人的代码，主要是之前没意识到strlen()函数可以使用。知道后就用数组存储，遇到左括号存入，遇到右括号就跟最近一次存入的左括号比对，如果匹配上，就直接把这两个抹去,以'\0'写入数组，
以此循环往复。
最后检查数组的0元素是否为'\0',如果是就是匹配成功，
当然中间如果有直接不匹配的，直接返回false
### 代码

```c
bool isValid(char * s){
    
    int len=strlen(s);
    bool rtn=false;
    if(len==0)
        return true;

    char str[len];
    if(len%2!=0)
        rtn=false;
    else {
        for(int i=0;*s!='\0';s++,i++){
            if(*s=='('||*s=='['||*s=='{')
                str[i]=*s;
            else{
                i--;
                if(i<0)
                    rtn=false;
                else{
                switch (*s){
                    case ')':
                        if(str[i]=='('){
                            str[i]='\0';
                            i--;
                            rtn= true;
                        }else
                           return false;
                        break;
                    case ']':
                        if(str[i]=='['){
                            str[i]='\0';
                            i--;
                            rtn= true;
                        }else
                           return false;
                        break;
                    case '}':
                        if(str[i]=='{'){
                            str[i]='\0';
                            i--;
                            rtn= true;
                        }else
                           return false;
                        break;
                    default:
                       return false;
                }}
                
            }
            //else
            //  rtn=false;
        }

    }


    if(str[0]!='\0')
        rtn=false;

    return rtn;
}
```