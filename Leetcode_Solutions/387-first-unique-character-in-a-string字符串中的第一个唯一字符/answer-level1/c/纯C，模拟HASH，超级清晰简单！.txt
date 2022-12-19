```
int firstUniqChar(char * s){
    int mark[26];//标记数组
    memset(mark,0,sizeof(mark));
    int i,length=strlen(s);
    for(i=0;i<length;i++)//记录个数
        mark[s[i]-'a']++;
    for(i=0;i<length;i++)
        if(mark[s[i]-'a']==1)
        return i;
    return -1;
}
```

