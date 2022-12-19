### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(char **a,char **b){
    return  -strcmp(*a,*b);
}
int cmp(int *a,int *b){
    return *b - *a;
}
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    if(wordsSize==1){
        *returnSize = k;
        return words;
    }
    qsort(words,wordsSize,sizeof(char*),comp);
    *returnSize = k;
    char **ans,*temp;
    temp = words[0];
    int *num,top=-1,count=1;
    ans = (char**)malloc(sizeof(char*)*k);
    num = (int*)malloc(sizeof(int)*wordsSize);
    for (int i=1;i<wordsSize;i++){
        if (strcmp(temp,words[i])==0)
            count++;
        else{
            num[++top] = wordsSize*count + i-1;
            temp = words[i];
            count = 1;
        }
    }
    if (strcmp(temp,words[wordsSize-1])==0)
        num[++top] = count*wordsSize + wordsSize-1;
    else
        num[++top] = wordsSize+wordsSize-1;
    qsort(num,top+1,sizeof(int),cmp);
    for (int i=0;i<top+1;i++){
        num[i] %= wordsSize;
    }
    for (int i=0;i<k;i++)
        ans[i] = words[num[i]];
    return ans;
}
```