### 解题思路
1. 遍历读取原数组
2. 奇偶异步写入器写入返回数组

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    
    int *res = (int *)malloc(sizeof(int) * ASize);
    // 异步写入器
    int write_1= 0, write_2 =1;
    for (int i=0; i<ASize; i++){
        if (A[i] %2 == 0){
            res[write_1] = A[i];
            write_1 += 2;
        }else{
            res[write_2] = A[i];
            write_2 += 2;
        }
    }
    return res;
}
```