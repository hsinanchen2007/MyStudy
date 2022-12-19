### 解题思路
就是两个一组，奇数个偶数的值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    var arr = []
    for (var i = 0;i < nums.length - 1; i+=2){
        for (var j = 0;j < nums[i];j++){
            arr.push(nums[i+1])
        }
    }
    return arr
};
```