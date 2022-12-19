### 解题思路
思路比较简单，遍历所有可能情况

### 代码

```c
int firstUniqChar(char * s){
    int i,j;
    int len;
    int flag=0;
    len=strlen(s);
    if(len==0){
        return -1;
    }
    if(len==1){
        return 0;
    }
    for(i=0;i<=len-1;i++){
        for(j=0;j<=len-1;j++){
            if(i!=j&&s[i]==s[j]){
                break;
            }
        }
        if(j==len){
            flag=1;
            break;
        }
    }
    if(flag==1){
        return i;
    }
    return -1;
}
```