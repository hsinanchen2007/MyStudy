### 解题思路
1.如果串组为空，直接返回""，否则转2
2.依次比较串的每列，如果通过最后一串则前缀长+1,否则终止算法
3.由2得到窜的前缀长度，复制进新串

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    int len = 1,i,j;
    if(strsSize==0)return "";
    for(i=0;;i++){
        for(j=0;j<strsSize&&strs[0][i]==strs[j][i]&&strs[j][i]!='\0';j++);
        if(j==strsSize&&strs[0][i]!='\0')len++;
        else break;
        printf("%d ",len);
    }
    
    char* com_pre = (char*)malloc(sizeof(char)*len);
    for(i = 0;i<len-1;i++)
        com_pre[i] = strs[0][i];
    com_pre[i] = '\0';
    return com_pre;
}
```