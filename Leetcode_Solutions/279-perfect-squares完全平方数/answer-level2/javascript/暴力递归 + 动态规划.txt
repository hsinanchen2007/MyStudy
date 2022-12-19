### 解题思路
题是解出来了，但结果就是有点惨不忍睹; 不知道从哪优化了

> 这是递归的
![image.png](https://pic.leetcode-cn.com/8392683573da291ff836fef5d9177568e6dae058a106791b123e042d84aa4225-image.png)


> 这是动态规划的
![image.png](https://pic.leetcode-cn.com/b010114437fb0b727c46b5fd8e71100420639f321e4a056fb49f41ea1ffb471f-image.png)

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numSquaresWithRecursive = function(n) {
  // 缓存加持，并没有提高多少；但没有缓存，基本就超时
  const cache = {};
  function mathSquare(val, count) {
      if (cache[val]) {
          return cache[val];
      }
      let min = val;
      let res = Math.sqrt(val);
      // 如果恰好能开平方，那就是+1的节奏
      if (res === Math.floor(res)) {
          cache[val] = count + 1;
          return count + 1;
      }
      res = Math.floor(res);
      // 遍历，寻找最小次数；
      for (let i = res; i > 0; i--) {
          // 这里感觉是可以优化的；以计算136的平方为例，会出现倒着回去算的情况：即i = 2， next = 132 这种，完全浪费时间；
          const next = val - i * i;
          let res = next;
          if (i === 1) {
              res = 1 + count + next;
          } else {
              // 计算出来了 + 1, 是因为 i * i，占了一次
              res = 1 + mathSquare(next, count);
          }
          min = Math.min(min, res);
      }
      // 缓存结果
      cache[val] = min;
      return count + min;
  }
  return mathSquare(n, 0);
};

/**
* 动态规划：不太容易想到；但从个别数的计算上，感觉是比不上递归的速度；
*/
function numSquares(n) {
    const cache = {
        '0' : 0
    }
    for(let i = 1; i <= n; i++) {
        const k = Math.floor(Math.sqrt(i))
        // 计算 j <= 0 是没有意义的，为什么？自己琢磨，另外i >= j * j这个也是
        for(let j = k ; i >= j * j && j > 0; j --) {
            cache[i] = Math.min(cache[i] || n, cache[i - j*j] + 1)
        }
    }
    return cache[n]
}
```