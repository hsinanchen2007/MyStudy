### 解题思路
此处撰写解题思路

### 代码

```c


int splitArray(int* nums, int numsSize, int m){
    long high = 0, low = 0, mid;
    int i;
    for (i = 0; i < numsSize; i++) {
        high += nums[i];
        low = low > nums[i] ? low : nums[i];
    }

    long temp = 0;
    int cnt;
    while (low < high) {
        temp = 0;
        cnt = 1;
        mid = (low + high) / 2;
        for (i = 0; i < numsSize; i++) {
            temp += nums[i];
            if (temp > mid) {
                cnt++;
                temp = nums[i];
            }
        }
        if (cnt > m) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}


```