### 解题思路
用栈就行了，比较简单，就不赘述了，自己看代码吧

### 代码

```c
char str[100010];
char * minRemoveToMakeValid(char * s){
    char stack[100010];
    int i,k=0,n,pos[100010],j,h[100010]={0};
    n=strlen(s);
    for(i=0;i<n;i++){
        if(s[i]=='('){
            stack[k]=s[i];
            pos[k]=i;
            k++;
        }
        else if(s[i]==')'){
            if(k>0&&stack[k-1]=='('){
                stack[k-1]='\0';
                pos[k-1]=-1;
                k--;
            }
            else{
                stack[k]=s[i];
                pos[k]=i;
                k++;
            }
        }
    }
    for(j=0;j<k;j++){
        h[pos[j]]=1;
    }
    k=0;
    for(j=0;j<n;j++){
        if(h[j]==0){
            str[k++]=s[j];
        }
    }
    str[k]='\0';
    return str;
}
```