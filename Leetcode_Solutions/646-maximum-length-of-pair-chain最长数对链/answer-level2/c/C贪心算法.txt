```
typedef struct Pair{
    int start;
    int end;
}Pair;
Pair PairMatrix[1000];
int cmp(void * pa, void * pb) {
    return (((Pair*)pa)->end - ((Pair*)pb)->end);
}
int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){
    int len = 0;
    int ret = 1;
    Pair temp;

    for (len = 0; len < pairsSize; len++) {
        PairMatrix[len].start = pairs[len][0];
        PairMatrix[len].end = pairs[len][1];
    }
    /* 对后续排序 */
    qsort(PairMatrix, pairsSize, sizeof(Pair), cmp);

    if (len < 0) {
        return 0;
    }

    temp = PairMatrix[0];

    for (len = 1; len < pairsSize; len++) {
        if (PairMatrix[len].start > temp.end) {
            ret ++;
            temp = PairMatrix[len];
        }
    }
    return ret;
}

```
