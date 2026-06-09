### 解题思路
核心思想就是i 位的个数，是  i& (i-1) 个数 再加上1，因为i & (i -1) 就是消掉二进制最后一个1.

### 代码

```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
  let arr = new Array(num +1).fill(0);
  for(let i =1 ;i< arr.length ;i++){
      arr[i] = arr[i & (i-1)] +1
  }
  return arr
};
```