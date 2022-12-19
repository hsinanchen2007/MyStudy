### 解题思路
先升序排列，从数组头开始遍历，数组头是最小的数，要能形成组，则一定有一组以它开头。遍历在它之后的数组，将可以与他连成连续组的标记isUsed为1.数组头之后第一个isUsed的数一定是下一组的开头，重复操纵。

### 代码
//--------author：PeanutLiu-------------//
```c
int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool isNStraightHand(int* hand, int handSize, int W){
    if (handSize % W != 0)  return false;
    int *isUsed = (int *)calloc(handSize, sizeof(int));
    qsort(hand, handSize, sizeof(int), comp);
    for (int i = 0; i < handSize; i++) {
        if (isUsed[i])  continue;
        isUsed[i] = 1;
        int cnt = 1, tmp = hand[i];
        for (int j = i + 1; j < handSize; j++) {
            if (!isUsed[j] && hand[j] - tmp == 1) {
                tmp = hand[j];
                isUsed[j] = 1;
                cnt++;
            }
            if (cnt == W) break;
            if (j == (handSize - 1) && cnt < W)  return false; //找不到足够的数形成组，故false
        }
    }
    return true;
}
```