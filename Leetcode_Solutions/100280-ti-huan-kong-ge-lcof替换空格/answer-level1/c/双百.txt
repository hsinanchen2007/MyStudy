### 解题思路
就遍历

### 代码

```c
char* replaceSpace(char* s){
    int i=0,j=0,sum=0;
    while(s[i]!=0){
        if(s[i]==' '){
            sum+=2;
        }
        sum++;
        i++;
    }
    char*res=(char*)malloc((sum+1)*sizeof(char));
    res[sum]=0;
    i=0;
    while(s[i]!=0){
        if(s[i]!=' '){
            res[j++]=s[i++];
        }else{
            i++;
            res[j++]='%';
            res[j++]='2';
            res[j++]='0';
        }
    }
    return res;
}
```