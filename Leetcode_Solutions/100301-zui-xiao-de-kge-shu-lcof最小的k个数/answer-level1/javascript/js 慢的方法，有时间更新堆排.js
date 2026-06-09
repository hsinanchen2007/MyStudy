![image.png](https://pic.leetcode-cn.com/7aa4df6a1fa8ec610ec6e0cbceec39ba2087d6687fdd9d0c248abf6f8fad2695-image.png)

### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */

/*
  132ms
  直观方法，直接快排，然后拿前k个小的数
*/
var getLeastNumbers = function(arr, k) {
  arr.sort((a, b) => a - b);
  return arr.slice(0, k);
};
```