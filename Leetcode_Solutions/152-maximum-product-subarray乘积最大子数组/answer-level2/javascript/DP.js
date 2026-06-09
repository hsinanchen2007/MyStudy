### 解题思路
递归思想，有最优子结构，考虑DP
两个点比较重要：
1.有负数，所以保存一下最小值，如果是负数，就将MAX和MIN对换，乘完和当前数值比较
2.和num[i]比较，就是去除0的情况

最后记着把整个计算的最大最小值记录下来。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
  let max = 1 , min = 1 ,allMax= nums[0]
  for(let i = 0; i< nums.length ; i++){
      if(nums[i] < 0){
          let temp = max;
          max = min;
          min = temp;
      }
      max = Math.max(max * nums[i] ,nums[i])
      min = Math.min(min * nums[i], nums[i])
      allMax = Math.max(max , allMax)
  }
  return allMax
};
```