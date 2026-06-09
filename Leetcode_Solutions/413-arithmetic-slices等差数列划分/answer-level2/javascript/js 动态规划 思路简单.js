![image.png](https://pic.leetcode-cn.com/9d46577dc2e40fb66c1413e611d010f34397e0851b4c984bdbd155fbb5a3d0d6-image.png)

### 解题思路
```javascript
看完评论只觉得自己是个智障
分析下思路：
从第三个元素i开始，判断以当前元素为结尾的三个数是不是等差数列
  - 如果是，那么以当前数为结尾的等差数组个数为 dp[i - 1] + 1
  - 如果不是，那么以当前数为结尾的等差数组的个数为 0
```

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */

var numberOfArithmeticSlices = function(A) {
  let ans = 0,
      dp = [];
  dp[0] = 0;
  dp[1] = 0;
  
  for (let i = 2, ALen = A.length; i < ALen; i++) {
    if (A[i] - A[i - 1] === A[i - 1] - A[i - 2]) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 0;
    }
    ans += dp[i];
  }
  
  return ans;
};
```