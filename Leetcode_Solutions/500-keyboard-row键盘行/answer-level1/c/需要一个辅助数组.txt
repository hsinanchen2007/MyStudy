### 解题思路
代码将近有百行，amazing，代码这么多行的原因是分类讨论了大小写的情况，占了很多行代码，看了有其他人的解答，发现用tolower()这个函数能省很多事。。。学到了，还是这些基本函数运用不够熟练。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize){
    char **res=NULL;
    int i,j,len;
    int count=0;
    int k=0;
    int a;
    int m,n;
    int flag[26]={2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
    for(i=0;i<wordsSize;i++){
        len=strlen(words[i]);
        if(len==1){
            count++;
            continue;
        }
        j=1;
        if(words[i][j-1]>='a'&&words[i][j-1]<='z'){
            m=words[i][j-1]-'a';
        }
        else if(words[i][j-1]>='A'&&words[i][j-1]<='Z'){
            m=words[i][j-1]-'A';
        }
        if(words[i][j]>='a'&&words[i][j]<='z'){
            n=words[i][j]-'a';
        }
        else if(words[i][j]>='A'&&words[i][j]<='Z'){
            n=words[i][j]-'A';
        }
        while(j<=len-1&&flag[m]==flag[n]){
            j++;
            if(j<=len-1){
                if(words[i][j-1]>='a'&&words[i][j-1]<='z'){
                    m=words[i][j-1]-'a';
                }
                else if(words[i][j-1]>='A'&&words[i][j-1]<='Z'){
                    m=words[i][j-1]-'A';
                }
                if(words[i][j]>='a'&&words[i][j]<='z'){
                    n=words[i][j]-'a';
                }
                else if(words[i][j]>='A'&&words[i][j]<='Z'){
                    n=words[i][j]-'A';
                }
            }
        }
        if(j==len){
            count++;
        }
    }
    res=(char **)malloc(sizeof(char *)*count);
    for(i=0;i<wordsSize;i++){
        len=strlen(words[i]);
        if(len==1){
            res[k]=(char *)malloc(sizeof(char)*2);
            res[k][0]=words[i][0];
            res[k][1]='\0';
            k++;
            continue;
        }
        j=1;
        if(words[i][j-1]>='a'&&words[i][j-1]<='z'){
            m=words[i][j-1]-'a';
        }
        else if(words[i][j-1]>='A'&&words[i][j-1]<='Z'){
            m=words[i][j-1]-'A';
        }
        if(words[i][j]>='a'&&words[i][j]<='z'){
            n=words[i][j]-'a';
        }
        else if(words[i][j]>='A'&&words[i][j]<='Z'){
            n=words[i][j]-'A';
        }
        while(j<=len-1&&flag[m]==flag[n]){
            j++;
            if(j<=len-1){
                if(words[i][j-1]>='a'&&words[i][j-1]<='z'){
                    m=words[i][j-1]-'a';
                }
                else if(words[i][j-1]>='A'&&words[i][j-1]<='Z'){
                    m=words[i][j-1]-'A';
                }
                if(words[i][j]>='a'&&words[i][j]<='z'){
                    n=words[i][j]-'a';
                }
                else if(words[i][j]>='A'&&words[i][j]<='Z'){
                    n=words[i][j]-'A';
                }
            }
        }
        if(j==len){
            res[k]=(char *)malloc(sizeof(char)*(len+1));
            for(a=0;a<len;a++){
                res[k][a]=words[i][a];
            }
            res[k][len]='\0';
            k++;
        }
    }
    *returnSize=count;
    return res;
}
```