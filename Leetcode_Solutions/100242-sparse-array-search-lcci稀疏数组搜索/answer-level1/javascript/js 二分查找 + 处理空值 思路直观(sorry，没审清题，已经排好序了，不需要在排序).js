![image.png](https://pic.leetcode-cn.com/1d2ac17af1d08bc39785c03c5b099f596780b94cde1ef8ef2865b7eb12d580df-image.png)

### 解题思路
```js
二分查找
注意处理空值，遇到空值，low high 指针向中间移动即可，
如果是每次二分取得的中间数为空，那就让他向右移动，但是不能大于右指针
(向左移动也可以，但是不能小于左指针，此处的目的同样也是跳过空值)
```

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} s
 * @return {number}
 */

var findString = function(words, s) {
  let low = 0,
      high = words.length - 1,
      ans = -1;
  
  // words.sort((a, b) => a - b);
  
  while (low <= high) {
    while (words[low] === '' && low < high) low++;
    while (words[high] === '' && low < high) high--;
    
    let mid = low + ( (high - low) >> 1 );
    while (words[mid] === '' && mid < high) mid++;
    
    if (words[mid] === s) {
      ans = mid;
      break;
    }
    
    if (s < words[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  
  return ans;
};
```