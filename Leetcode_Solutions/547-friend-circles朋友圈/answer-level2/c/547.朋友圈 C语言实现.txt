递归删除一个圈的流程以下图为例，有点儿乱，见谅
![image.png](https://pic.leetcode-cn.com/e13a1d89691fccdb74e53ce3cda6e2bb272d13684669db2d7ff4f8feb6aeb444-image.png)

/* 删除某节点所有的朋友圈，深度优先遍历 */
void DeleteAllFriend(int** M, int MSize, int owner)
{
    int j;

    M[owner][owner] = 0;

    for (j = 0; j < MSize; j++) {
        if (M[owner][j] == 1) {
            M[owner][j] = 0;
            M[j][owner] = 0;
            DeleteAllFriend(M, MSize, j);
        }
    }
}

/* 遍历朋友圈，注意删除朋友圈的时候，要把对角线上的删除 */
int findCircleNum(int** M, int MSize, int* MColSize)
{
    int i;
    int num = 0;

    for (i = 0; i < MSize; i++) {
        if (M[i][i] == 1) {
            num++;
            DeleteAllFriend(M, MSize, i);
        }
    }

    return num;
}


