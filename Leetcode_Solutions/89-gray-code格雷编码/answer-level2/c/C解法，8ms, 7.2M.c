**思路**
根据规律来，以n == 4为例：
0 0 0 0
0 0 0 1
       ->最后一位上下对称
0 0 1 1
0 0 1 0
       ->最后两位上下对称
0 1 1 0
0 1 1 1
0 1 0 1
0 1 0 0
       ->最后三位上下对称
1 1 0 0
1 1 0 1
1 1 1 1
1 1 1 0
1 0 1 1
1 0 0 1
1 0 0 0
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    
    if (n == 0) {
        int *out = (int *)malloc(1 * sizeof(int));
        out[0] = 0;
        *returnSize = 1;
        return out;
    }
    
    *returnSize = 1 << n;
    //printf("%d ", num);
    int *out = (int *)malloc((*returnSize) * sizeof(int));
    out[0] = 0;
    out[1] = 1;
    
    int idx = 2;
    int preIdx = 1;
    for (int i = 1; i < n; i++) {
        int cycle = 1 << i;
        for (int j = 0; j < cycle; j++) {
            out[idx] = cycle + out[preIdx];
            preIdx--;
            idx++;
        }
        preIdx = idx - 1;
    }
    return out;
}


```
