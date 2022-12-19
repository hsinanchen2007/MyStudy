### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

int maxDistance(int** arrays, int arraysSize, int* arraysColSize){
    int ans = 0;
    int min = arrays[0][0];
    int max = arrays[0][arraysColSize[0] - 1];

    for (int i = 1; i < arraysSize; i++) {
        int val1 = abs(min - arrays[i][arraysColSize[i] - 1]);
        int val2 = abs(max - arrays[i][0]);
        ans = MAX(ans, MAX(val1, val2));
        //printf("val1:%d, val2:%d, ans:%d\n", val1, val2, ans);
        //min max 代表前i-1个数组中的最大值和最小值，然后和第i个数组比较，依次更新，这个是关键
        min = MIN(min, arrays[i][0]);
        max = MAX(max, arrays[i][arraysColSize[i] - 1]);
    }
    return ans;
}
```