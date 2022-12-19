### 解题思路
此处撰写解题思路
思路：二分法
1、判断最小的数是否在第一个位置，若是则返回nums[0];
2、否则，选取中间位置 mid 的数和 r 位置的数进行比较，若nums[mid] < nums[r]，说明最小的数在mid之前，r = mid；反之，令 l = mid+1;
3、重复进行，直到 l >= r。
### 代码

```c

int findMin(int* nums, int numsSize){
    int l = 0;
    int r = numsSize - 1;
    if(nums[l] < nums[r])
    {
        return nums[l];
    }
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(nums[mid] > nums[r])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return nums[l];
}


```