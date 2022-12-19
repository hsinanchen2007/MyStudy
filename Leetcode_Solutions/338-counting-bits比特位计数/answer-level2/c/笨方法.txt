### 解题思路


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int bitNum[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
    int i;
    int *result = (int *)malloc((num+1)*sizeof(int));    

    for( i = 0; i <= num; i++ ) {
        result[i] = bitNum[i & 0xf] + 
                    bitNum[(i >> 4) & 0xf] + 
                    bitNum[(i >> 8) & 0xf] + 
                    bitNum[(i >> 12) & 0xf]+
                    bitNum[(i >> 16) & 0xf] + 
                    bitNum[(i >> 20) & 0xf] + 
                    bitNum[(i >> 24) & 0xf] +
                    bitNum[(i >> 28) & 0xf];
    }

    *returnSize = num+1;

    return result;
}
```