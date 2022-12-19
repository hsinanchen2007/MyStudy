![image.png](https://pic.leetcode-cn.com/23ad3f376ef20b5b337b770ef037632addcee64c53024395988fd5047f556011-image.png)

### 解题思路
```js
  最直观做法 map 存储每个数字出现的次数，一旦出现重复的数字，立即返回即可
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var findRepeatNumber = function(nums) {
  let map = {}, ans = null;
  
  for (let i = 0, n = nums.length; i < n; i++) {
    let c = nums[i];
    if (map[c] === undefined) {
      map[c] = 1;
    } else {
      ans = c;
      break;
    }
  }
  
  return ans;
};
```