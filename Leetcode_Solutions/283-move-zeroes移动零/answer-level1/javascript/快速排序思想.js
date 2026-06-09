### 解题思路
快速排序思想，就是要找到一个点，小于这个点的放左边，大于这个点的放右边
所以这个题，只要判断大于0的都放到左边
注意点就是indx，放一次，J就要加1，然后用J继续做下标

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    if(nums == null || nums.length ==1){return nums}

    let j = 0;
    for(let i= 0; i < nums.length; i++){
        if(nums[i] != 0){
            let temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            ++j
        }
    }
    return nums
};
```