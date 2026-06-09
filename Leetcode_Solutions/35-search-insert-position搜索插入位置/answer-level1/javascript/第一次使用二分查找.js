### 解题思路
使用2分查找 Math.floor((start=0 + end=nums.length-1)/2)的到中间索引值（比较阶接近的索引）然后和target做对比，等于的话直接返回中间索引，大于的的话end=midIndex-1，小于的话 sart=midIndex+1，再求中间值 类推直到star<=end

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let start = 0;
    let end =nums.length-1;
    while(start<=end){
        const midIndex = Math.floor((start+end)/2);
        const mid = nums[midIndex];
        if(mid===target){
            return midIndex
        }else if(mid>target){
            end=midIndex-1
        }else{
            start=midIndex+1
        }
    }
    return start
}
```