### 解题思路
思路简单清晰，代码中都有注释。
但这个方法导致时间复杂度很高，仅供大家参考吧，因为这是一种比较简单易懂的方法。

### 代码

```c
/*按字符串长度由大到小排序*/
int compare(const void* _a, const void* _b){
    char **a=(char**)_a;
    char **b=(char**)_b;
    return strlen(*b) - strlen(*a);
}
/*leetcode的28题，检察字符串包含关系的第一次出现位置*/
/*C语言的<string.h>里好像自带strstr()的函数，但我没用，选择了自己当初写的*/
int strStr(char * haystack, char * needle){
    int i=0,j=0,pos=-1,count=0;
    int length_h=strlen(haystack);
    int length_n=strlen(needle);
    if(length_n==0) pos=0;
    if(length_h<length_n) pos=-1;
    else{
        while(i<length_h && j<length_n){
            if(haystack[i]==needle[j]){
                if(j==0) pos=i;
                i++;
                j++;
            }
            else{
                if(pos>=0) i=pos+1;
                else i++;
                j=0;
                pos=-1;
            }
        }
        if(j<length_n) pos=-1;
    }
    return pos;
}
int minimumLengthEncoding(char ** words, int wordsSize){
    if(words==NULL)
        return 0;
    qsort(words,wordsSize,sizeof(char*),compare);
    char *res=(char*)malloc(sizeof(char)*20000);
    int index=0;
    strcpy(res,words[0]);
    strcat(res,"#");
    for(int i=1;i<wordsSize;i++){
        index=strStr(res,words[i]);
        if(index<0){
            strcat(res,words[i]);
            strcat(res,"#");
        }
        else{
            /*这里需要检查是否是后缀，例如abbc和bb，使用strStr返回的index=1，但bb不是abbc的后缀*/
            if(res[index+strlen(words[i])]!='#'){
                strcat(res,words[i]);
                strcat(res,"#");
            }
        }
    }
    return strlen(res);
}
```