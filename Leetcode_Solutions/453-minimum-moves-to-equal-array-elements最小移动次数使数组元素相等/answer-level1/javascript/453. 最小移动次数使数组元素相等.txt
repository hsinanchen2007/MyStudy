通过数学归纳法得出~
思路评论区都是：
n-1个元素都+1，等价于只将一个元素-1，等价于所有的数与最小值的差值的和
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    let min = Math.min.apply(null,nums);
    let path = 0;
    for(let i = 0 ,len = nums.length;i<len;i++){
        path += nums[i]-min;
    }
    return path;
};
```