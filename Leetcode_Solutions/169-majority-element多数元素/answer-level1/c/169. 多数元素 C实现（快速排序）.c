### 解题思路
此处撰写解题思路

### 代码

```c
int Compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), Compare);
    int cnt = 1;
    int lim = numsSize / 2;
    int ans = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] != nums[i]) {
            cnt = 1;
            continue;
        }
        cnt++;
        if (cnt > lim) {
            ans = nums[i];
            break;
        }
    }
    return ans;
}
```