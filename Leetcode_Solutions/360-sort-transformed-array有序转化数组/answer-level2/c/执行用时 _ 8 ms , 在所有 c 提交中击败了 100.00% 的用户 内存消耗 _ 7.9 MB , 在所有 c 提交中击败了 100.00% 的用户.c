```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortTransformedArray(int* nums, int numsSize, int a, int b, int c, int* returnSize){
    int *res = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    if (a == 0) {
        for (int i = 0;i < numsSize;i++) {
            if (b > 0) {
                res[i]  = b * nums[i] + c;
            } else if (b < 0) {
                res[i]  = b * nums[numsSize - 1 - i] + c;
            } else {
                res[i] = c;
            }            
        }
        return res;
        
    }
    
    float midLine = -(float)b / ((float)a * 2.0);
    int str = 0;
    int end = numsSize - 1;
    int i = 0;
    while (str <= end) {
        float diffS = (float)nums[str] - midLine;
        float diffE = (float)nums[end] - midLine;
        if (fabs(diffS) >= fabs(diffE)) {
            res[i] = nums[str] * nums[str] * a + b *  nums[str] + c;
            str++;
        } else {
            res[i] = nums[end] * nums[end] * a + b *  nums[end] + c;
            end--;
        }
        i++;
    }

    if  (a > 0) {
        int j = 0;
        while (j < (i / 2)) {
            int tmp = res[j];
            res[j] = res[numsSize - 1 - j];
            res[numsSize - 1 - j] = tmp;
            j++;
        }
    }
    return res;
}
```
