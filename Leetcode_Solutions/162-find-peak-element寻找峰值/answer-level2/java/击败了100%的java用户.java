## [更多leetcode分类题解](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)



由于nums[-1] = nums[n] = -∞,则峰值一定存在，所以用二分的话，if(nums[mid] > nums[mid + 1])表示左侧存在，否则去右侧找

```
public int findPeakElement(int[] nums) {
        if(nums.length == 1){
            return nums[0];
        }

        int start = 0;

        int end = nums.length - 1;

        int mid;

        while (start < end) {

            mid = start + (end - start) / 2;
            //表示左侧存在

            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            } else {
                start = mid + 1;
            }

        }
        return start;

    }
```
