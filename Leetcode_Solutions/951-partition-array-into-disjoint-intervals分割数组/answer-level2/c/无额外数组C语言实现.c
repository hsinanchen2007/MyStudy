解这道题主要是要明白左右分割的界限在哪里：
==leftMax < rightMin==
所以一次遍历的时候我们要这么做：
1. 找到左侧最大值后，后面的搜索只要是数值小于leftMax的，都是左数组
2. 碰到第一个大于leftMax时，记录pos和这个值，然后继续搜索
3. 如果后续搜索值都大于leftMax，那么分割完毕（注意，每次更新右侧最大值，因为不满足的情况下，我们要更新leftMax）
4. 如果不满足，那么更新leftMax和pos，继续搜索
如此，完成搜索，返回pos位置 + 1即可，[0, pos]就是最小left数组
![截图.PNG](https://pic.leetcode-cn.com/da556d1d964512e85ab5c0a4e371e8267d10db08a51265f74c1aa86b0d525865-%E6%88%AA%E5%9B%BE.PNG)

```c
int partitionDisjoint(int *A, int ASize) {
    int pos = 0;
    int leftMax = A[0];
    int temp = 0;

    int i = 1;
    while (i < ASize) {
        if (leftMax > A[i]) {
            ++i;
            continue;
        }

        temp = A[i];
        pos = i - 1;
        ++i;
        while (i < ASize) {
            if (A[i] > temp)
                temp = A[i];

            if (A[i] >= leftMax) {
                ++i;
                continue;
            }

            pos = i;
            leftMax = temp;
            break;
        }
    }

    return pos + 1;
}
```