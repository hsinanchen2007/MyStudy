### 解题思路
先排序 排序后取最大的值
因为是三个值相乘  那么我们另外两个值
要么是 正数 要么是负数
排序后的位置 要么是 最后两个 要么是2、3位的
所以利用Math.max比较

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumProduct = function(nums) {
    nums.sort((a,b)=>{return a-b})
    let num1=nums[0]*nums[1]*nums[nums.length-1]
    let num2=nums[nums.length-3]*nums[nums.length-2]*nums[nums.length-1]
    return Math.max(num1,num2)
};
```