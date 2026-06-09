### 解题思路
感觉有些哈希的思想

### 代码

```c
int firstUniqChar(char * s){
    int i,j;
    int len;
    int flag[26]={0};
    len=strlen(s);
    if(len==0||len==1){
        return len-1;
    }
    for(i=0;i<len;i++){
        flag[s[i]-'a']++;
    }
    for(i=0;i<len;i++){
        if(flag[s[i]-'a']==1){
            break;
        }
    }
    if(i==len){
        return -1;
    }
    return i;
}
```