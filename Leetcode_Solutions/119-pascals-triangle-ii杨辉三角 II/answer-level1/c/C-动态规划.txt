### 解题思路

和118题一样，只不过这次不需要二维数组了，只需要一维数组即可。

另外注意，这里的0就是第一行，因此不需要加入一行，判断是否为0.

两外就是，状态转移方程是`res[j] = res[j-1] + res[j];`, 因此我们需要从后往前，从前往后会收到之前的影响。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){

    *returnSize = rowIndex + 1;

    int *res = (int *)malloc( sizeof(int) * (rowIndex + 1));
    //初始化都为1
    for (int i = 0; i < rowIndex+1; i++) res[i] = 1;

    for (int i = 1; i < rowIndex; i++){
        for(int j = i; j >=0 ; j--){
            if (j == 0 || j == (rowIndex + 1)) {
                res[j] = 1;
            } else{
                res[j] = res[j-1] + res[j];
            }

        }
    }
    return res;

}
```