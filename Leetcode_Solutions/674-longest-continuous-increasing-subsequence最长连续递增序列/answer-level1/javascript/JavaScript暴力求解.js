### 解题思路
* 每次循环中，判断两者的值，最后用三元判断进行对max重新赋值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findLengthOfLCIS = function(nums) {
    let len = nums.length
    let max = 1, count = 1
    if(!len) return 0
    for( let i = 0; i < len -1 ; i++){
        if(nums[i] < nums[i+1]){
            count++
        }
        else{
            count = 1
        }
        max = max > count ? max : count
    }
    return max
};
```