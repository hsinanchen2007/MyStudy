### 解题思路
遍历判断、数组移除

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */


// 遍历判断 是否相等。  不相等则根据 下标 count 替换
var removeElement = function(nums, val) {
    let count = 0
    for(let i=0; i<nums.length; i++){
        if( nums[i] != val ) {
            nums[count] = nums[i]
            count++
        }
    }
    return count
};

// 数组移除
// var removeElement = function(nums, val) {
//     let index = nums.indexOf(val)
//     while( index > -1 ) {
//         nums.splice(index,1)
//         index = nums.indexOf(val)
//     }
//     return nums.length
// };
```