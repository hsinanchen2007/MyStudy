### 解题思路
找出当前行和上一行的关系， 即可降低空间复杂度

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int i,j,l,temp;
    int *res = malloc((rowIndex+1) * sizeof(int));

    *returnSize = rowIndex+1;
    for(i=1;i<=rowIndex+1;i++){
        for(j=0;j<i;j++){
            if(j==0 || j==i-1){
                res[j] = 1;
                l = 1;
            }else {
                //利用当前行和上一行的关系
                temp = l + res[j];
                l = res[j];
                res[j] = temp;
            }
        }
    }
    return res;
}
```