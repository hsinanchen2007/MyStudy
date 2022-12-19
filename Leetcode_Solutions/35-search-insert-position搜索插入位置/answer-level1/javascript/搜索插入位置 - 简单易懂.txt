### 解题思路
![image.png](https://pic.leetcode-cn.com/84019acfd2c308cb877cc63ec5e6386c44b8df32d5dc58a3fbbd16b15c1bd2d2-image.png)
简单易懂的解法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

// for
var searchInsert = function(nums, target) {
    const index = nums.indexOf(target)
    if( index > -1 ) return index
    for(var i=0; i<nums.length; i++){
        if(target < nums[i]) return i
    }
    return i
};

// while
// var searchInsert = function(nums, target) {
//     const index = nums.indexOf(target)
//     if( index > -1 ) return index
//     let i = 0
//     while( i < nums.length ){
//         if(target < nums[i]) return i
//         i++
//     }
//     return i
// };

//  内置函数
// var searchInsert = function(nums, target) {
//     // if( nums.includes(target) ) return nums.indexOf(target)
//     nums.push(target)
//     return nums.sort((a,b)=>a-b).indexOf(target)
// };
```