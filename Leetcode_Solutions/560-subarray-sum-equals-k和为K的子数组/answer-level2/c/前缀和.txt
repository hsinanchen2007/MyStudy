### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_NUM     20001

int sum[MAX_NUM] = {0};

int subarraySum(int* nums, int numsSize, int k){
    if (!nums || numsSize < 1) {
        return 0;
    }

    for (int i = 0; i < MAX_NUM; i++) {
        sum[i] = 0;
    }

    sum[0] = nums[0];
    if (numsSize == 1) {
        if (sum[0] == k) {
            return 1;
        } else {
            return 0;
        }
    }
    for (int i = 1; i < numsSize; i++) {
        sum[i] = nums[i] + sum[i - 1];
    }

    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j <= i; j++) {
            if (k == sum[i] - sum[j] + nums[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}
```