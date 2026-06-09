### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(char *a,char *b){
    return *a-*b;
}
int f(char *s){
    int k=1,i;
    qsort(s,strlen(s),sizeof(char),cmp);
    for(i=1;i<strlen(s);i++){
        if(s[i]==s[0]) k++;
        else return k;
    }
    return k;
}
int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
    int i,j,k,*a,b[queriesSize],c[wordsSize];
    a=(int*)malloc(sizeof(int)*queriesSize);
    *returnSize=queriesSize;
    for(i=0;i<queriesSize;i++)
        b[i]=f(queries[i]);
    for(i=0;i<wordsSize;i++)
        c[i]=f(words[i]); 
    for(i=0;i<queriesSize;i++){
        k=0;
        for(j=0;j<wordsSize;j++){
            if(b[i]<c[j])
                k++;
        }
        a[i]=k;
    } 
    return a;
}
```