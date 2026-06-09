### 解题思路
有序用二分法是快的方式 
题目的难点是如何确定最后的边界，
题目的的判断 是通过加1 或者减1 来最后结束循环的 在结束循环的过程中 最后一步的判断必然是left=right
这个mid就是这个值 ，所有只要判断是mid的前面还是后面

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    if(nums[0] >= target || nums.length == '0') {
        return 0;
    }
    if(nums[nums.length-1] < target) {
        return nums.length;
    }
        let left = 0, right  = nums.length-1;
         let mid = 0;
        while(left <= right) {
            mid = left + right >>>1;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] >target) {
                right = mid-1;
            }
             if(nums[mid] <target) {
                left = mid+1;
            }
            
        }
           if (mid > 0 && nums[mid] > target)
            {
                mid = mid;
            }                                           
            else if(nums[mid] < target)
            {
                mid = mid + 1;
            }
            return mid;

};
```