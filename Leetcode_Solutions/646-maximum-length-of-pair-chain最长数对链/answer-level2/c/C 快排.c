把一个数对看成（start，end）
step1：用把二维数组做按end大小做升序排列；
step2：遍历每一个元素，每当前一个数对的end与小于下一个数对的start时，length++（length初值为1，题目最少给出一个数对）；

```
int cmp (const void* a, const void* b)
{
    const int *pa = *(const int **)a;
    const int *pb = *(const int **)b;
    return pa[1] - pb[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){
    int i,j;
    int length = 1;
    qsort(pairs,pairsSize,sizeof(int *), cmp);
    for(i = 0; i< pairsSize; i++) {
    }
    j = 0;
    for(i = 0; i< pairsSize - 1; i++) {
        if(pairs[j][1] < pairs[i + 1][0]) {
            j = i + 1;
            length++;
        }
    }
    *pairsColSize = 2;
    return length;
}
```
