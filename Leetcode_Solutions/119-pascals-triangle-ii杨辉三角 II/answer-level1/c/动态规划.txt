### 解题思路
用pre数组保存i-1行数据
用cur数组表示d第i行数据
求当前值：
cur[i] = pre[i-1] + pre[i];
下一次循环：
memcpy(pre, cur, sizeof(int)*rows);
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int* cur = malloc(sizeof(int)*(rowIndex + 1));
    int* pre = malloc(sizeof(int)*(rowIndex + 1));
    if(rowIndex < 0) return cur;
    for(int i = 0; i <= rowIndex; i++){
        int rows = i + 1;
        for(int j = 0; j < rows; j++){
            if(j == 0 || j == rows - 1) {
                pre[j] = 1;
                cur[j] = 1;
            }
            else cur[j] = pre[j-1] + pre[j];
        }
        memcpy(pre, cur, sizeof(int)*rows);
    }
    return cur;
}
```