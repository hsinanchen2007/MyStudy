### 解题思路
此处撰写解题思路

### 代码

```c
char * reverseStr(char * s, int k){
    if(strlen(s)<=k){
        for(int i=0;i<strlen(s)/2;i++){
            char tmp = s[i];
            s[i]=s[strlen(s)-1-i];
            s[strlen(s)-1-i]=tmp;
        }
    }else{
        for(int i=0;i<k/2;i++){
            char tmp = s[i];
            s[i]=s[k-1-i];
            s[k-1-i]=tmp;
        }
        if(strlen(s)>2*k)
            reverseStr(s+2*k,k);
    }
    return s;
}
```