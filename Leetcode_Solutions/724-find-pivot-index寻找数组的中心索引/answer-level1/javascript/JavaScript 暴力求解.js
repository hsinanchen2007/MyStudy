### 解题思路
* 基本思路：leftSum + rightSum + item = Sum;
* 通过array.reduce()得到数组的Sum值
* 通过findIndex找到第一个符合目标的index，通过true确认，否则继续遍历

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    let leftSum = 0
    let sum = nums.reduce(
    (i,j) => (i+j), 0
    )
    
    return nums.findIndex((item) =>{
        if((sum - item - leftSum) === leftSum){
            return true
        }
        leftSum = leftSum + item
    })
    
};
```