### 解题思路
看

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let len = nums.length;
    //等差数
    let s = len * (len+1) / 2;
    //和
    let sum = nums.reduce((acc,curr)=>{
        return acc + curr
    },0)
    return s-sum
};
```