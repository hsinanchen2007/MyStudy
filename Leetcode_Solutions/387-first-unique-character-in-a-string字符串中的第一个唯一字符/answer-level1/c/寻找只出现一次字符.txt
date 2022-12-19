### 解题思路
，问就是 hash

### 代码

```c
int firstUniqChar(char * s){
    int flag[26]={0};    //初始化
    int len=strlen(s);
    int i;
    for(i=0;i<len;i++){
        flag[s[i]-'a']++;
    }
    for(i=0;i<len;i++){
        if(flag[s[i]-'a']==1) return i;
    }
    return -1;
    
}
```