### 解题思路
桶排
![image.png](https://pic.leetcode-cn.com/a84956247170556f3e248ea429a7f6c47108772e2584e1202afdd820aa3f68cc-image.png)

### 代码

```c
#define MAX_CH_NUM 26
#define MAX_SIGNLE_CH_NUM 110
int chCount[MAX_CH_NUM];
int singleCount[MAX_CH_NUM];
char* singleCh;
int countCharacters(char ** words, int wordsSize, char * chars){
    if(words == NULL || wordsSize<1 ||chars == NULL) {
        return 0;
    }
    //先桶排序看一下每个字母有多少个
    memset(chCount, 0 ,sizeof(int) * MAX_CH_NUM);
    int chLen = 0;
    chLen = strlen(chars);
    int temp;
    for(int i=0 ; i < chLen; i++) {
        temp = chars[i] - 'a';
        chCount[temp]+=1;
    }
    //判断是否有足够多的字符能够组成，如果可以组成就计数
    int resCnt = 0;
    int singleLen = 0;
    int bOk = 1;
    singleCh = malloc(sizeof(int) * MAX_CH_NUM);
    for (int j=0 ; j < wordsSize; j++) {
        singleCh = words[j];
        singleLen = strlen(singleCh);
        memset(singleCount, 0 ,sizeof(int) * MAX_CH_NUM);
        for(int k=0 ; k < singleLen; k++) {
            temp = singleCh[k] - 'a';
            singleCount[temp]+=1;
            if(singleCount[temp] > chCount[temp]) {
                 bOk = 0;
                  break;
            }
           
        }

        if (bOk){
           // printf("j=%d %s wordsSize = %d\n",j,singleCh, wordsSize);
           resCnt +=  singleLen;
        }
        bOk = 1;
    }
    return resCnt;
}
```