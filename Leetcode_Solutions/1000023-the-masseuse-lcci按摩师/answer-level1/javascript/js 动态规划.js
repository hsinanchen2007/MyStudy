![image.png](https://pic.leetcode-cn.com/eead1d3129bd338fec7085a732a6ed95057f537b799a573376cbbb0406d02388-image.png)

### 解题思路
```js
  类似股票问题，两次预约之间要休息一天
  
  动态规划：
  
  两种情况：
  dp0: 表示到昨天，昨天没有接服务的状态
  dp1: 表示到昨天，昨天接了服务的状态
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var massage = function(nums) {
  if (nums.length === 0) return 0;
  let dp0 = 0, dp1 = nums[0], n = nums.length;
  
  for (let i = 1; i < n; i++) {
    let receive = dp0 + nums[i],
        noReceive = Math.max(dp0, dp1);
    dp0 = noReceive;
    dp1 = receive;
  }
  
  return Math.max( dp0, dp1 );
};
```