![image.png](https://pic.leetcode-cn.com/deee713eb08ea8e297823ca9bb3ef1aba0e79dd14e34401da5d4ca6b5af801c7-image.png)

### 解题思路
```js
思路：
- 问：刚好在 H 小时吃完香蕉的最小速度
- 初始化最慢为 0，最快速度为香蕉数组的最大值
- 找到刚好可以吃完的最小速度，也就是不超时的最大速度，如果当前速度 k = 5 满足条件，
  那么继续向左半区查找，可能还会有比 5 更小的值满足，直到没有更小的速度可以满足条件
  返回 low 即为最小速度
```

### 疑问
为什么 [1,1,1,1,2] 2 的答案是2呢？
如果警察两小时后就会回来，珂珂的速度是一小时吃两根香蕉，他怎么可能吃完 [1,1,1,1,2] 这五堆香蕉呢？

### 代码

```javascript
/**
 * @param {number[]} piles
 * @param {number} H
 * @return {number}
 */

var minEatingSpeed = function(piles, H) {
  let low = 0,
      high = Math.max( ...piles );
  
  function finished(k) {
    let time = 0;
    
    for (let i = 0; i < piles.length; i++) {
      time += Math.ceil(piles[i] / k);
    }
    
    return time <= H;
  }
  
  while (low < high) {
    let mid = low + ( (high - low) >> 1 );
    if (finished(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  
  return low;
};



```