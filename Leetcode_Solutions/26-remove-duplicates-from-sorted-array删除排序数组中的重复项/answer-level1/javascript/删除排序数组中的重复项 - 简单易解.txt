### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var removeDuplicates = function(nums) {
    let index = 0
    for( let i=0,len=nums.length; i<len; i++ ){
        if( nums[i] != nums[i+1] ) {
            nums[index] = nums[i]
            index++
        }
    }
    return index
};

// var removeDuplicates = function(nums) {
//     let i = 0
//     while( i < nums.length ){
//         if( nums[i] == nums[i+1]){
//             nums.splice(i+1, 1)
//             i--
//         }
//         i++
//     }
//     return i
// };
```