![image.png](https://pic.leetcode-cn.com/d465f91b406419f69b8040a0b5bf41fb5464e859daaa6553bbf81452e55b80fd-image.png)

### 解题思路
```js
  除了 1 和 本身之外，有且仅有一对不相等的因子才统计它的和，重点是判断条件
  举两个反例：
  16：是不行的：因为他有多个因数 1 2 4 8 16，
  如果结果为 134716980 的这个用例跑不过去，可以拿 16 来调试
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var sumFourDivisors = function(nums) {
  let sum = 0;
  
  for (let i = 0; i < nums.length; i++) {
    let num = nums[i];
    if (num < 5) continue; // 这里没啥意义，0 1 2 3 4 一定不符合条件，当然 5 也不符合，但是就不用脑子往后考虑了，让程序去计算吧
    
    let prefix_two = 1 + num,
        midRoot = Math.sqrt(num),
        findRes = 0,
        suffix_two = null;
    
    for (let j = 2; j <= midRoot; j++) {
      let temp = num / j;
      if (num % j === 0) {
        findRes++;
        
        if (findRes === 1 && temp !== j) {
          suffix_two = temp + j;
        } else {
          break;
        }
      }
    }
    
    if (findRes === 1 && suffix_two !== null) {
      sum += (suffix_two + prefix_two);
    }
  }
  
  return sum;
};
```