
![Snipaste_2020-03-06_11-36-13.jpg](https://pic.leetcode-cn.com/af394b098a4d392e1e90c788f0a4ec704b4c47b85ca06412eba31587a5ff9379-Snipaste_2020-03-06_11-36-13.jpg)

### 代码

```c
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int low = 0, high = numsSize - 1, mid;
    int* res = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(nums[mid] == target)
        {
            low = mid;
            high = mid;
            while(low >= 0 && nums[low] == target)
            {
                low--;
                if(low == -1)
                    break;
            }
            res[0] = low + 1;
            while(high <= numsSize-1 && nums[high] == target)
            {
                high++;
                if(high == numsSize)
                    break;
            }
            res[1] = high - 1;
            return res;
        }
        else if(nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    res[0] = -1;
    res[1] = -1;
    return res;
}
```