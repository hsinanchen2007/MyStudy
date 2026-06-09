```
bool CheckExist(int *s, int a)
{
    return a == s[0] || a == s[1];
}
void UpdateSum(int *max, int sum)
{
    if (sum > *max) {
        *max = sum;
    }
}
int totalFruit(int* tree, int treeSize)
{
    int totalSum = 0;
    int totalSumMax = 0;
    int totalKind = 0;
    int exist[2] = {-1, -1};
    int begin =  0;

    for (int i = 0; i < treeSize; i++) {
        if (CheckExist(exist, tree[i])) {
            totalSum++;
            //printf("tree[%d]=%d is already exsit, totalSum=%d\n", i, tree[i], totalSum);
        } else {
            if (totalKind == 0) {
                begin = i;
            }
            totalKind++;
            totalSum++;
            if (totalKind <= 2) {
                exist[totalKind - 1] = tree[i];
                //printf("tree[%d]=%d is not exsit, totalSum=%d, totalKind=%d\n", i, tree[i], totalSum, totalKind);
            } else {
                exist[0] = -1;
                exist[1] = -1;
                UpdateSum(&totalSumMax, totalSum - 1);
                totalSum = 0;
                totalKind = 0;
                //printf("tree[%d]=%d is overflow, totalSumMax=%d\n", i, tree[i], totalSumMax);
                i = begin;
                //printf("restart tree[%d]=%d\n", i, tree[i]);
            }
        }
    }
    //printf("end\n");
    UpdateSum(&totalSumMax, totalSum);
    return totalSumMax;
}
```
