![image.png](https://pic.leetcode-cn.com/1fea04b0e068614c57038dbdf5f1b915b3d3c99665c9a1db0f6c4aa0daeb8ef4-image.png)

### 解题思路
```js
  以每一个数为结尾，查看所有组合是否能组成作战单位
```

### 代码

```javascript
/**
 * @param {number[]} rating
 * @return {number}
 */

var numTeams = function(rating) {
  let count = 0, n = rating.length;
  
  for (let i = 2; i < n; i++) {
    for (let j = i - 1; j >= 1; j--) {
      for (let k = 0; k < j; k++) {
        if (
          (rating[i] > rating[j] && rating[j] > rating[k]) ||
          (rating[i] < rating[j] && rating[j] < rating[k]) 
        ) {
          count++;
        } 
      }
    }
  }
  
  return count;
};
```