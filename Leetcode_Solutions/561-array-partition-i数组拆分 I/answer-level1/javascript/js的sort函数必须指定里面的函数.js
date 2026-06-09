### 解题思路
sort函数如果不指定里面的参数，就会按照字符的大小来排序，而不是按照数值的大小

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    nums.sort((a,b)=>a-b);
    var sum=0;
    for(var i=0;i<nums.length;i+=2){
        sum +=nums[i];
    }
    return sum;
};
```