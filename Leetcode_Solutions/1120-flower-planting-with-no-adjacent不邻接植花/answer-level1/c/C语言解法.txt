1. 将每一个花园与之路径相通的花园记录下来；
2. 从标记为1的花园开始，遍历与它直接连接的花园种植花的种类，将这些花从`flowers[4] = {1, 2, 3, 4}`中去除，然后在剩余花中选出值最小的一个花种类种植到该花园中。

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize){
    int *answer = (int *)calloc(N, sizeof(int)); // 保存答案
    int gardenAdjLists[N][3]; // 保存每一个花园的与之路径相通的花园（最多三个）
    int *gardenAdjIndex = (int *)calloc(N, sizeof(int)); // 保存每个邻近花园数组的下标
    int row, col, idx, f; // 临时变量
    
    // 为了方便数组操作，都将花园数值减1。
    for (int i = 0; i < pathsSize; i++) { // paths[i] = [x, y]

        // 保存y到x的邻近花园数组
        row = paths[i][0] - 1; 
        col = gardenAdjIndex[row]++;
        gardenAdjLists[row][col] = paths[i][1] - 1;
        
        // 保存x到y的邻近花园数组
        row = paths[i][1] - 1;
        col = gardenAdjIndex[row]++;
        gardenAdjLists[row][col] = paths[i][0] - 1;
    }

    //打印gardenAdjLists
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < gardenAdjIndex[i]; j++) {
    //         printf("%d ", gardenAdjLists[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < N; i++) { // 确定answer[i]的值
        int flowers[4] = {1, 2, 3, 4};
        for (int j = 0; j < gardenAdjIndex[i]; j++) { // 对每一个花园的与之道路相通的花园中种植花的种类进行遍历
            idx = gardenAdjLists[i][j];
            f = answer[idx];
            if (f > 0) flowers[f - 1] = 0; // 将该花园周围已经种植的花种类置0
        }
        for (int k = 0; k < 4; k++) { // 将flower中第一个不为0的值赋予answer[i]
            if (flowers[k] != 0) {
                answer[i] = flowers[k];
                break;
            }
        }
    }
    free(gardenAdjIndex);
    *returnSize = N;
    return answer;
}
```
