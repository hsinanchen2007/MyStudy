### 解题思路
此处撰写解题思路

### 代码

```c


int subarraySum(int* nums, int numsSize, int k){
    int left, right, temp, res;
    int *sum = NULL;

    if (nums == NULL || numsSize <= 0) {
        return 0;
    }

    sum = (int *)malloc(sizeof(int) * numsSize);
    sum[0] = nums[0];
    res = 0;

    for (left = 1; left < numsSize; left++) {
        sum[left] = nums[left] + sum[left - 1];
    }

    for (left = 0, right = 0; right < numsSize; right++) {
        temp = sum[right];

        while (left <= right) {
            if (temp == k) {
                res++;
            }
            temp -= nums[left++];
        }
        left = 0;
    }
    
    free(sum);
    return res;    
}

```