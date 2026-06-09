
```
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    int i=0,j=0,num=strlen(strs[0]);
```
**从第二个字符串开始，后面的每个字符串与第一个字符串按字符依次比较，
统计与第一个字符串的公共前缀长度，
与前一次得到的公共前缀长度(初始为第一个字符串的长度)比较，取较小值
某一次求得的公共前缀长度为零，返回空字符串**
```
    for(i=1;i<strsSize;i++){
        j=0;
        while((strs[i][j]==strs[0][j])&&(strs[0][j]!='\0')){
            j++;
        }
        if(j<num){
            num=j;
        }
        if(num==0) return "";
    }
```
**将公共前缀复制到输出字符串中**
```
    char* s;
    s=(char*)malloc((num+1)*sizeof(char));
    for(int k=0;k<num;k++){
        s[k]=strs[0][k];
    }
    s[num]='\0';
    return s;
}
```

