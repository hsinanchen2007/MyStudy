### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    quickSort(nums, 0, nums.length - 1 )
    return nums;

};

function quickSort(nums ,left, right) {
    if (left === right) return;
    if (left < right) {
        let pivot = nums[left];
        let i = left;
        let j = right;
        while(i<=j) {
           while (i <= j && nums[i] < pivot) i++;
            while (i <= j && nums[j] > pivot) j--;
            if (i <= j) {
                let temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
                j--;
            }
        }
        if (left <= j) {
            quickSort(nums, left, j);
        } 
         if (i <= right) {
            quickSort(nums, i, right);
        }
    }

}

```