### 解题思路

本题初看类似于“最长递增子序列”问题，但差别点在于：**判断除大于和小于外的剩余情况过多，无法使用简单的栈维护**。

因此回归最本质的解法，“**维护每个箱子能够叠加的最高高度，然后新增箱子，需要对之前箱子遍历判断**”。

1.建立状态数组dp。

2.根据长宽高进行排序。

3.根据排序结果进行遍历，如果当前箱子i可以落在前面某个箱子j的底部，则记录下能当前达到的最大高度tmp_dep

4.遍历所有前面确认过的箱子，找到最大高度，更新到dp[i]中

5.如果dp[i] > max，则更新max

6.遍历所有箱子，返回max。


![image.png](https://pic.leetcode-cn.com/41f60aadf3ad99af32ead009e595dc62d81f066886ce2a25c25b64b47dcd6305-image.png)



### 代码

```c
#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MAX_NUM     3000

int dp[MAX_NUM];

int compare(const void *a, const void *b) {
    int **aa = (int **)a;
    int **bb = (int **)b;

    if((*aa)[0] != (*bb)[0]) {
        return (*aa)[0] - (*bb)[0];
    } else if((*aa)[1] != (*bb)[1]) {
        return (*aa)[1] - (*bb)[1];
    } else if((*aa)[2] != (*bb)[2]) {
        return (*aa)[2] - (*bb)[2];
    } else {
        return 0;
    }
}

//比较s和d，只有当s所有值都大于d，返回1；都小于返回-1；否则为0；
int box_cmpare(int *d, int *s) {
    if(s[0] > d[0] && s[1] > d[1] && s[2] > d[2]) {
        return 1;
    } else if(s[0] < d[0] && s[1] < d[1] && s[2] < d[2]) {
        return -1;
    } else {
        return 0;
    }
}

//【算法思路】dp+排序。
// 注意，二分已经无法解决，因为存在大量除大于和小于外的状态
int pileBox(int** box, int boxSize, int* boxColSize){
    if(boxSize == 0) {
        return 0;
    } else if(boxSize == 1) {
        return box[0][2];
    }

    qsort(box, boxSize, sizeof(int*), compare);

    int dsize = 0;
    dp[dsize++] = box[0][2];

    int max = box[0][2];
    for(int i = 1; i < boxSize; i++) {
        int max_dep = box[i][2];
        for(int j = 0; j < i; j++) {
            if(box_cmpare(box[j], box[i]) == 1) {
                max_dep = MMAX(max_dep, dp[j] + box[i][2]);
            }
        }

        dp[i] = max_dep;
        if(max_dep > max) {
            max = max_dep;
        }
    }

    return max;
}
```