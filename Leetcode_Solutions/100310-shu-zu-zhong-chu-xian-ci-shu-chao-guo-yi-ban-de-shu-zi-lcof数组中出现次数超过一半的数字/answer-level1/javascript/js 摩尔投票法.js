![image.png](https://pic.leetcode-cn.com/f600772d89f8e8014c7312fbdedc114198ad1fd7c0a4a6669966d72257316422-image.png)

### 解题思路
```js
  摩尔投票法：
  如果有一个数字出现的次数超过数组的一半，那么使用摩尔投票法，
  最后一定会留下出现次数最多的那个数
  
  首先假设第一个数为众数，遍历数组，只要和当前众数相等，那么票数 +1
  如果不相等，票数 -1，如果票数为 0，那么继续假设下一个数为众数
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var majorityElement = function(nums) {
  let vote = 0, goal = null, n = nums.length;
  
  for (let i = 0; i < n; i++) {
    let c = nums[i];
    if (vote === 0) goal = c;
    if (c === goal) {
      vote += 1;
    } else {
      vote -= 1;
    }
  }
  
  return goal;
};
```