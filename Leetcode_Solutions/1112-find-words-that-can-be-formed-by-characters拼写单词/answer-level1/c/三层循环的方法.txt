### 解题思路
第一层循环，遍历所有单词，第二层循环，遍历单词的字母，第三层循环，遍历字母表字母匹配。
为了防止一个单词重复匹配到字母表中的字母，每次成功匹配都置0,下一个单词重新恢复字母表。
不会什么算法，瞎写的，大概就是这样。

### 代码
```c
int countCharacters(char ** words, int wordsSize, char * chars){
    #define TRUE 1
    #define FALSE -1
    int flag;
    int n=wordsSize,m;
    int i,j,z;
    int q=strlen(chars);
    char *temp_chars; 
    int sum=0;

    temp_chars = (char*)malloc(sizeof(char)*q);
    memcpy(temp_chars,chars,q);
    for(i=0;i<n;i++) //单词++
    {
        flag=TRUE; //初始化、重置匹配状态。
        m=strlen(words[i]); //当前单词长度
        for(j=0;j<m;j++) //单词内字母++
        {
           for(z=0;z<q;z++) //匹配的字符串字母++
           {
               if(words[i][j] == temp_chars[z]) //匹配成功
               {
                   temp_chars[z]=0; //置零，防止重复匹配。
                   break;
               }
           }
           if(z>=q) //匹配不到字母
           {
               flag=FALSE;
               break; //下一个单词
           }
        }
        memcpy(temp_chars,chars,q); //恢复字符串
        if(flag!=FALSE)
        {
            sum+=m;
        }
    }
    return sum;
}
```