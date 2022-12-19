### 解题思路
reduce函数的高级用法传入一个函数参数：reduce(function(total，当前元素，当前索引，当前的数组),total的初始值)。其中函数function(total，当前元素，当前索引，当前的数组)需要返回值return total;

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let max = -Infinity;
    nums.reduce((total,cur,i)=>{
        if( total > 0 ) total += cur;
        else total = cur;
        
        //console.log(total);
        max = max > total?max:total;
        return total;
    },0)
    return max;
};
```