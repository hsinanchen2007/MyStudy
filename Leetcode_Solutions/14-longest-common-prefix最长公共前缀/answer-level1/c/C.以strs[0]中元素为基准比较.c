### 解题思路
1.找出二维数组中最短的那个数组
2.每个二维数组中的数组元素中的每个元素按下标比较，记录长度
3.起始位置为0，按长度截取字符串并返回

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(!strsSize) return "\0";
   int minlen=100000000;
   int clen=0;int flag=0;
   for(int i=0;i<strsSize;i++) {
       if(strlen(strs[i])==0) return "\0";
       if(strlen(strs[i])<minlen) minlen=strlen(strs[i]);
   }
   for(int i=0;i<minlen;i++){
       for(int j=1;j<strsSize;j++){
           if(strs[j][i]!=strs[0][i]) {
             flag=1;break;
           }
       }
       if(flag) break;
       else clen++;
   }
   char *s=(char *)malloc(clen+1);
   strncpy(s,strs[0],clen);
   s[clen]='\0';
   return s;
}
```