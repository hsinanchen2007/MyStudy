### 解题思路
二分法并不是所有情况都使用，当出现 nums[ileft] == nums[imid] == nums[iright] 时无法区分最小值是在左区间还是右区间，此时，需要遍历从ileft到iright所有值，找出最小。不过官方的算例没有出现这种情况。来自《剑指offer》的提醒。。。
算例{1, 0, 1, 1, 1, 1, 1}和{1, 1, 1, 1, 1, 0, 1}
### 代码

```c
int findMin(int* nums, int numsSize){
    int ileft = 0, iright = numsSize - 1, imid;

    if(nums[iright] > nums[ileft])
        return nums[ileft];

    while(iright > ileft)
    {
        imid = ileft + (iright - ileft) / 2;
        if(nums[imid] > nums[iright])
        {
            if(nums[imid + 1] < nums[imid])
                return nums[imid + 1];
            ileft = imid + 1;
        }
        // 注意算例[1, 1, 1, 1, 1, 0, 1]
        // 当出现 nums[ileft] == nums[imid] == nums[iright] 时遍历 ileft 到 iright 所有值
        else if(nums[imid] == nums[ileft] && nums[imid] == nums[iright])
        {
            int ii = ileft;
            while(ii != iright)
            {
                if(nums[ii + 1] < nums[ii])
                    return nums[ii + 1];
                ii++;
            }

            return nums[ileft];
        }
        else
            iright = imid;
    }

    return nums[ileft];
}
```