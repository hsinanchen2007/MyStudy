### 解题思路
前缀思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    let arr = (new Array(100)).fill(0), result = []
    for(let i = 0; i < nums.length; i++){
        arr[nums[i]] += 1
    }
    for(let i = 1; i < arr.length; i++){
        arr[i] += arr[i - 1]
    }
    for(let i = 0; i < nums.length; i++){
        let _r = arr[nums[i] - 1] || 0
        result.push(_r)
    }
    return result
};
```