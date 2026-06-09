### 解题思路
此题要求是正方形，并且所有的点要都参与到，步骤如下：
（1）求所有的和sum，除4个边target = sum / 4，每个边都应该是一样的（正方形），如果无法整除，返回false；
（2）如果可以整除，先排序（从大到小），这里使用qsort排序（可以使用多种方法，堆、归并、希尔等都可以），如果最大值比target大，返回false；
（3）dfs搜索，如[15,14,13,12,11,10,9,8,7,6,5,4,3,2,1]，target = 30，我们就可以找到15+14+1这种，从大到小找，所有值都应用，所以必须要有解，无解说明无法拼出正文形；
如果可以找出四组，且所有值都被应用，则为true，否则为false;
![123.PNG](https://pic.leetcode-cn.com/d8000e3b887a9bd91579972f546b4458df7a6208902930f3829a036ca5539482-123.PNG)


### 代码

```c
int target;
int numLen;
int dfs(int *visit, int idx, int *pCnt, int *nums, int sum)
{
    int succ = 0;
    sum += nums[idx];
    visit[idx] = 1;
    (*pCnt)++;
    if (sum == target) {
        return 1;
    }
    if (sum > target) {
        return 0;
    }
    for (int i = 0; i < numLen; i++) {
        if (visit[i] == 0) {
            succ = dfs(visit, i, pCnt, nums, sum);
            if (succ == 1) {
                return succ;
            } else {
                (*pCnt)--;
                visit[i] = 0;
            }
        }
    }
    return 0;
}
int cmp(const void *ele1, const void *ele2)
{
    int *p1 = (int *)ele1;
    int *p2 = (int *)ele2;
    if (*p1 > *p2) {
        return -1;
    }
    if (*p1 < *p2) {
        return 1;
    }
    return 0;
}
bool makesquare(int* nums, int numsSize) {
    if (nums == NULL) {
        return false;
    }
    int boundary, sum;
    boundary = sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 4 != 0) {
        return false;
    }
    target = sum / 4;
    numLen = numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    int *visit = NULL;
    visit = (int *)malloc(sizeof(int) * numsSize);
    int cnt, succCnt;
    cnt = succCnt = 0;
    memset(visit, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (visit[i] == 0) {
            succCnt += dfs(visit, i, &cnt, nums, 0);
        }
        if (cnt == numsSize && succCnt == 4) {
            return true;
        }
    }
    return false;
}
```