![image.png](https://pic.leetcode-cn.com/c58ce3f8b0c349b9c45925b800a594be61155503466da27e22266019c339a4e1-image.png)

### 解题思路
```js
  哈希记录：如果统计到某个数的出现次数大于 n/2，直接返回
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var majorityElement = function(nums) {
  let map = {}, ans = null, n = nums.length;
  
  for (let i = 0; i < n; i++) {
    let c = nums[i];
    if (map[ c ] === undefined) {
      map[ c ] = 1;
    } else {
      map[ c ]++;
    }
    
    if (map[ c ] > n / 2) {
      ans = c;
      break;
    }
  }
  
  return ans;
};
```