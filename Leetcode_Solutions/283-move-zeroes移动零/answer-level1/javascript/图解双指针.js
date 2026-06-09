思路:

双指针，i用来遍历数组，j表示最后一个0的下标

当i 遇到 0时，i++
当i 不是 0 时，j+1,如果j<i,nums[j] = nums[i], nums[i] =0

![move-zeroes](https://pic.leetcode-cn.com/dfca524b7a77be74ad5dcc8dc6bb6750182df3a132a78ae7b9aabea89fb6e1b0-file_1575470344883)

```javascript
var moveZeroes = function(nums) {
    let i = 0, j=0
    while(i < nums.length){
        if (nums[i] != 0){
            if (j < i){
                nums[j] = nums[i]
                nums[i] = 0
            }
            j++
        }
        i++
    }
    return nums
};
```