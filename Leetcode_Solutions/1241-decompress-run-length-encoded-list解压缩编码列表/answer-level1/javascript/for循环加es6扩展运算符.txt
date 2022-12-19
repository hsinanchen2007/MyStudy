### 解题思路
两两相比较，存入一个数组里返回

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    let countArr = []
    for (let i=0; i<nums.length; i+=2) {
        
        countArr = [...countArr, ...Array(nums[i]).fill(nums[i+1])]
        
    }
    return countArr
};
```