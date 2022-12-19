![image.png](https://pic.leetcode-cn.com/29ae735e3cc5cbec34cf7594300ece14ac89e9a5ccdf03ecdef0f98c00b9f077-image.png)

### 解题思路
```js
二分搜索
如果正在上坡，那么峰顶一定在后面，否则在前面
A[mid] < A[mid + 1] -> 上坡 -> low = mid + 1
else -> high = mid
```

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */

var peakIndexInMountainArray = function(A) {
  let low = 0,
      high = A.length - 1;
  
  while (low < high) {
    let mid = low + ( (high - low) >> 1 );
    
    if (A[mid] < A[mid + 1]) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  
  return low;
};
```