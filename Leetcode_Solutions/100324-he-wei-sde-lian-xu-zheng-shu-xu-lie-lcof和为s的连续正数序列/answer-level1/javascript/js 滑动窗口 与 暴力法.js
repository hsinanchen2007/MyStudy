![image.png](https://pic.leetcode-cn.com/d95069da5d8fb99417da103fb47398d3a5c1a0447b3787e3c109197593fc7d07-image.png)

### 解题思路
```js
滑动窗口
```

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */

var findContinuousSequence = function(target) {
  let ans = [], start = 1, end = 1, arr = [], sum = 1;
  
  for (let i = 1; i < target; i++) arr.push(i);
  
  while (end < target) {
    if (sum === target) {
      ans.push( arr.slice(start - 1, end) );
      sum -= start;
      start++;
    } else if (sum < target) {
      end++;
      sum += end;
    } else if (sum > target) {
      sum -= start;
      start++;
    }
  }
  
  return ans;
}

/*
  100ms
  直观笨方法：
  从 1 开始，直到 target - 1，去尝试所有的可能
*/
// var findContinuousSequence = function(target) {
//   let ans = [], sum = 0, temp = [];
  
//   for (let i = 1; i < target; i++) {
//     for (let j = i; j < target; j++) {
//       if (sum + j > target) {
//         temp = [];
//         sum = 0;
//         break;
//       }
//       if (sum + j === target) {
//         temp.push(j);
//         ans.push([...temp]);
//         sum = 0;
//         temp = [];
//         break;
//       }
//       sum += j;
//       temp.push(j);
//     }
//   }
  
//   return ans;
// };
```