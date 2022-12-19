![image.png](https://pic.leetcode-cn.com/ab166de7c61d10fd38530632a2cf3e2df262d4b1bae55a30ff79c435b04e11c0-image.png)

### 解题思路
思路：让两个相邻的数最接近就好了
1. 正序排序
2. 从索引 0 开始累加值，每次索引向前移动两次
3. 不管数组的长度是奇数还是偶数，都可兼容，因为即使最后不足两位，也会把它加上

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
  nums.sort((a, b) => a - b);
  let sum = 0;
  
  for (let i = 0, len = nums.length; i < len; i += 2) {
    sum += nums[i];
  }
  
  return sum;
};
```