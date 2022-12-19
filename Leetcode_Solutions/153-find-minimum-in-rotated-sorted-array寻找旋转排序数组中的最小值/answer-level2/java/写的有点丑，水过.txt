![image.png](https://pic.leetcode-cn.com/ace2b554bae952a32638bdb4640002a38e7d5422e575699a2d24c5143209318f-image.png)


```
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int mid = left + (right - left) / 2;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(mid - left > 0) {
                if(nums[mid] < nums[mid - 1]) {
                    return nums[mid];
                }
            } else {
                if(nums[mid] < nums[right]) {
                    return nums[mid];
                } else {
                    return nums[right];
                }
            }
            if(nums[mid] > nums[right]) {
                left = mid;
                continue;
            }
            if(nums[mid] < nums[left]) {
                right = mid;
                continue;
            }
            if(nums[mid] >= nums[left] && nums[mid] <= nums[right]) {
                return nums[left];
            }
        }
        return nums[mid];
    }
```
