### 解题思路
执行用时 :0 ms, 在所有 c 提交中击败了100.00%的用户
内存消耗 :7 MB, 在所有 c 提交中击败了100.00%的用户

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* anagramMappings(int* A, int ASize, int* B, int BSize, int* returnSize){
    int i;
    int j;
    int *ret = (int*)malloc(sizeof(int) * ASize);
    
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < BSize; j++) {
            if (A[i] == B[j]) {
                ret[i] = j;
                j = BSize;
            }
        }
    }
    *returnSize = ASize;
    return ret;
}
```