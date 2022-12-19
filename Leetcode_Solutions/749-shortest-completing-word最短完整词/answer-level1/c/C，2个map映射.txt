![1.png](https://pic.leetcode-cn.com/7c68e7d2ba2cf661b21cc7d496cf6cad94533bbb33897dc0967ce636667a9745-1.png)

### 解题思路
map映射  licensePlate
t  映射  words[i]
num记录符合条件的words[i]的长度
最后取num中的非0最小下标

### 代码

```c
char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    int *map=(int*)calloc(26,sizeof(int)),*t=(int*)calloc(26,sizeof(int));
    int *num=(int*)calloc(wordsSize,sizeof(int)),j,k=0;
    while(*licensePlate){
        if(*licensePlate>='A' && *licensePlate<='Z')
            map[*licensePlate-'A']++;
        else if(*licensePlate>='a' && *licensePlate<='z')
            map[*licensePlate-'a']++;
        licensePlate++;
    }
    for(int i=0;i<wordsSize;i++){
        num[i]=strlen(words[i]); 
        memset(t,0,sizeof(int)*26);
        for(int l=0;l<num[i];l++)
            t[words[i][l]-'a']++;            
        for(j=0;j<26;j++)
            if(map[j]>t[j]){
                num[i]=0;
                break;
            }
    }
    j=1000;
    for(int i=0;i<wordsSize;i++)
        if(num[i]&&num[i]<j){
            j=num[i];
            k=i;
        }
    free(map);free(t);free(num);
    return words[k];
}
```