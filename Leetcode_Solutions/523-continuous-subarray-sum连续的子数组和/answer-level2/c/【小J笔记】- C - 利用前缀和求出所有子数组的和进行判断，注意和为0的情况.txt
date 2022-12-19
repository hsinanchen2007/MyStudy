- 利用前缀和求出所有子数组的和，判断是否为k的整数倍，注意k为0的情况
```
#define MAX_SIZE (10010)
#define NULL_PTR (0)
#define TRUE (1)
#define FALSE (0)

int g_preSum[MAX_SIZE];

bool checkSubarraySum(int* nums, int numsSize, int k)
{
    int i;
    int j;
    int val;
    if ((nums == NULL_PTR) || (numsSize <= 1)) {
        return FALSE;
    }
    g_preSum[0] = 0;
    for (i = 0; i < numsSize; i++) {
        g_preSum[i + 1] = nums[i];
        g_preSum[i + 1] += g_preSum[i];
    }
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {           
            val = g_preSum[j + 1] - g_preSum[i];
            if (k == 0) {
                if (val == 0) {
                    //printf("i = %d j = %d\n", i, j);
                    return TRUE;
                }       
            } else {
                if (val % k == 0) {
                    //printf("i = %d j = %d\n", i, j);
                    return TRUE;
                }                
            }                 
        }
    }
    return FALSE;    
}
```
