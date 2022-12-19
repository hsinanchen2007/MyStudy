#define MAX(a, b) (a > b) ? (a) : (b)

int leastBricks(int** wall, int wallSize, int* wallColSize){
    int hashmap[100000] = {0};
    int i, j;
    int sum;
    int max = 0;

    for (i = 0; i < wallSize; i++) {
        sum = 0;
        for (j = 0; j < wallColSize[i] - 1; j++) {
                // -1排除最右边边界的情况
            sum += wall[i][j];
            hashmap[sum]++;
                // 用数组作为哈希表存储，数组index为边界和，数组内容为边界和相同次数
            max = MAX(max, hashmap[sum]);
                // 找出数组中边界和次数最大值
        }
    }

    return wallSize - max;
}