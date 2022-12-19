找出第一大，把第一大从数组中删除。这样数组中最大的值就是第二大了，最后比较第一大是否是第二大的两倍

```
 /**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function(nums) {
    let max = Math.max(...nums)
    let maxIndex = nums.indexOf(max)
    nums.splice(maxIndex, 1)
    
    let secondMax = Math.max(...nums)
    if(max >= 2*secondMax){
        return maxIndex
    }
    return -1
};
```
