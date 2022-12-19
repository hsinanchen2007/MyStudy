### 解题思路
此处撰写解题思路
1.指定一个初始最大值，2.遍历输入的数组求和，拿和和拟定的最大值比较
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    var max = nums[0]
    var sum =0;
    nums.map(res=>{
        sum += res
        max = Math.max(max,sum) 
        if(sum<0){
            sum =0 
        }
        
    })
    return max
};
```