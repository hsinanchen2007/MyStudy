### 解题思路
栈的思想

### 代码

```c
bool isValid(char * s){
    if(s==NULL) return true;
    int n=strlen(s),i,k=-1;
    if(n%2!=0) return false;
    char *p=(char *)malloc(sizeof(char)*n);
    for(i=0;i<n;i++){
        if(s[i]==')'){//依次匹配压入的左括号，一起从p中去除
            if(k>-1&&p[k]=='('){
                k--;
            }
            else{
                return false;
            }
        }
        else if(s[i]==']'){
            if(k>-1&&p[k]=='['){
                k--;
            }
            else{
                return false;
            }
        }
        else if(s[i]=='}'){
            if(k>-1&&p[k]=='{'){
                k--;
            }
            else{
                return false;
            }
        }
        else{//压入左括号
            k++;
            p[k]=s[i];
        }
    } 
    if(k>-1) return false;
    return true;

}

```