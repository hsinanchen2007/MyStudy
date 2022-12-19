### 解题思路
此处撰写解题思路

### 代码

```c
int lengthOfLastWord(char * s){
    int len,i,j,count=0;
    len=strlen(s);
    for(i=0;i<len;i++){
        if(s[i]!=' ') count++;
    }
    if(len==0||count==0) return 0;
    for(i=len-1;i>=0;i--){
        if(s[i]!=' ') break;
    }
    for(j=i;j>=0;j--){
        if(s[j]==' ') break;
    }
    return i-j;
}
```