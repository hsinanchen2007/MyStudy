### 解题思路
此处撰写解题思路

### 代码

```c

#define MAX_CHAR_CNT 26
struct Ccnt {
    int idx;
    int cnt[MAX_CHAR_CNT];
};
int Comp(void * a, void *b)
{
    struct Ccnt *x = (struct Ccnt *)a;
    struct Ccnt *y = (struct Ccnt *)b;
    // 先循环比较，将排名次序前的票数多的，返回回去，按照降序
    for (int i = 0; i < MAX_CHAR_CNT; i++) {
        if (x->cnt[i] == 0 && y->cnt[i] == 0) continue;
        if (x->cnt[i] != y->cnt[i]) {
            return y->cnt[i] - x->cnt[i];
        }
    }
    // 到这里，意味着两个数的排名次序的票都一样，那么按照字母序返回；升序
    return x->idx - y->idx;
}
char * rankTeams(char ** votes, int votesSize){
    if (votesSize == 1) { // 只有一个队伍
        return votes[0];
    }
    // 所有参赛队伍投票一样
    int charCntInList; 
    int cIdx;   
    struct Ccnt pvoteCnt[MAX_CHAR_CNT] = {0};
    char *retBuf;
    charCntInList = strlen(votes[0]);
    
    // 字符出现的个数
    retBuf = (char *)malloc((charCntInList+1)*sizeof(char));
    memset(retBuf, 0, (charCntInList+1)*sizeof(char));
    if (charCntInList == 1) { // 只有1个字符
        retBuf[0] = votes[0][0];
        return retBuf;
    }
    // 遍历投票队伍，各个队伍中字符的多少
    for (int i = 0; i < votesSize; i++) {
        for (int j = 0; j < charCntInList; j++) {
            // 每个投票队伍
            int idx = (int)(votes[i][j] - 'A');
            pvoteCnt[idx].cnt[j]++;
            pvoteCnt[idx].idx = idx;
           // printf(" [%d][%d].%d %c ;",j,idx,pvoteCnt[idx].cnt[j],votes[i][j]);
        }
    }
    // pvoteCnt[j] 的各个值，为votes[0]中各个字符的加权值，按照从大到小的顺序输出

    qsort(pvoteCnt, MAX_CHAR_CNT, sizeof(struct Ccnt), Comp);
    /* 
    for (int i = 0; i < charCntInList; i++) {
        printf(" %d %d; ",i,pvoteCnt[i].idx);
    }*/
    cIdx= 0;    
    for (int i = 0; i < charCntInList; i++) {
        // if (pvoteCnt[i].cnt == 0) continue;
        retBuf[cIdx++] = pvoteCnt[i].idx + 'A';
    }      
    return retBuf;
}
```