![image.png](https://pic.leetcode-cn.com/f05db64c88de9f354bd665d54bced07bcda31b4fa11e24e9967001b2a7cac269-image.png)

### 解题思路
```js
类似 BFS
思路：
从每一个空座位出发，向左右两边走，只要有其中一边遇到人了，
那么拿当前走的最大距离和已保存的最大距离比较。
```

### 代码

```javascript
/**
 * @param {number[]} seats
 * @return {number}
 */

var maxDistToClosest = function(seats) {
  let ans = 0,
      n = seats.length;
  
  for (let i = 0; i < n; i++) {
    if (seats[i] === 0) {
      let count = 1,
          l = i - 1,
          r = i + 1;
      
      while (seats[l] !== 1 && seats[r] !== 1) {
        if (seats[l] === undefined && seats[r] === undefined) break;
        count++;
        l--;
        r++;
      }
      
      ans = Math.max(ans, count);
    }
  }
  
  return ans;
};



```