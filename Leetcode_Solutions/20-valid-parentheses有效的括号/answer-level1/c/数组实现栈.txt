### 解题思路
此处撰写解题思路
直接上代码
### 代码

```c
bool isValid(char * s){
    if(s==NULL) return true;
    char key[10000];
    int i, j;
    for(i=0,j=-1;s[i]!='\0';i++){
        if(j==-1){
             key[++j]=s[i];
             continue;
        }
        switch(s[i]){
            case '(' : 
            case '[' : 
            case '{' : key[++j]=s[i]; break;
            case ')' : 
                if(key[j]=='(') j--;
                else key[++j]=s[i];
                break;
             case ']' : 
                if(key[j]=='[') j--;
                else key[++j]=s[i];
                break;
             case '}' : 
                if(key[j]=='{') j--;
                else key[++j]=s[i];
                break;
            default : break;
        }
    }
    if(j==-1) return true;
    else return false;
}
```