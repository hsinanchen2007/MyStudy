### 解题思路
此处撰写解题思路

### 代码
![image.png](https://pic.leetcode-cn.com/e9073a69a089e4f8b10af53df6fbc168666b76c8628deff76b3d2c6a28bcde3d-image.png)

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    int **res = calloc(groupSizesSize ,sizeof(int*));
    *returnColumnSizes = calloc(groupSizesSize, sizeof(int));
    int res_index = 0;
    
    for (int i = 0; i < groupSizesSize; i++) {
        if (groupSizes[i]) {
            res[res_index] = calloc(groupSizesSize, sizeof(int));
            (*returnColumnSizes)[res_index] = groupSizes[i];

            int tmp = groupSizes[i];
            for (int j = 0; j < tmp; j++) {
                for (int k = 0; k < groupSizesSize; k++) {
                    if (groupSizes[k] == tmp) {
                        res[res_index][j] = k;
                        groupSizes[k] = 0;
                        break;
                    }
                }
            }
            res_index++;
        }
    }

    *returnSize = res_index;
    return res;
}
```