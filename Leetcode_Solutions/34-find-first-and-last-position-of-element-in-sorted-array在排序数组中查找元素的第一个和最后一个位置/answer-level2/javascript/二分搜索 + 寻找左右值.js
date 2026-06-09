### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let n = nums.length;
    if(n == 0) return [-1,-1];

    let leftBound = () => {
        let left = 0;
        let right = n;
        while (left < right) {
            let mid = (left + right) >> 1;
            if(nums[mid] == target){
                right = mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid;
            }
        }
        if(nums[left] != target) return -1;
        return left;
    }
    let rightBound = () => {
        let left = 0;
        let right = n;
        while(left < right){
            let mid = (left + right) >> 1;
            if(nums[mid] == target){
                left = mid + 1; 
            }else if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid;
            }
        }
        return left - 1;
    }

    let left = leftBound();
    if(left == -1) return [-1,-1];
    let right = rightBound();
    return [left,right];
}

```