![image.png](https://pic.leetcode-cn.com/9b687614c91389f5b098e5a50fcca9be629c4294b4ebe1233bf36335e731d6a0-image.png)

### 解题思路
```js
把 A 和 B 中的所有元素，从大到小依次放入 A 中
```

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */

var merge = function(A, m, B, n) {
  let i = m - 1, j = n - 1, p = m + n - 1;
  
  while (i >= 0 || j >= 0) {
    let l = i >= 0 ? A[i] : -Infinity,
        r = j >= 0 ? B[j] : -Infinity;
    
    if (l > r) {
      A[p] = l;
      i--;
    } else {
      A[p] = r;
      j--;
    }
    
    p--;
  }
  
  return A;
};
```