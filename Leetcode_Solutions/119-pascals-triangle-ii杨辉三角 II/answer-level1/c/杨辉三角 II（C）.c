### 解题思路
要求第k行,先给第k-1行后面补个１，然后从倒数第二项到正数第二项，每一项等于该项与其前一项之和。

### 代码

```c

int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int* p = (int*)malloc(sizeof(int) * (rowIndex + 1));
    int i, j, k = 0;
    for(i = 0; i <= rowIndex; i++){
        p[k++] = 1;
        for(j = i - 1; j >= 1; j--){
            p[j] += p[j-1];
        }
    }
    return p;
}
```