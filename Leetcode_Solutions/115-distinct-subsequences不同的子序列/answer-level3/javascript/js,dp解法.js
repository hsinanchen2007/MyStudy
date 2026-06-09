[原发于github](https://github.com/feikerwu/algorithm-camp/issues/4)

### 题解
子序列 T 在 S 中出现的次数 = T - 1 在 S 中的次数 + T - 1 在 S - 1 中出现的次数（前提是 S[-1] === T[-1]）

写成动态规划方程
![](http://latex.codecogs.com/gif.latex?f(T,%20S)%20=%20%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20f(T,%20S-1),%20T%5B-1%5D%20!==%20S%5B-1%5D%20&%20%5C%5C%20f(T,%20S-1)+f(T-1,%20S-1),%20T%5B-1%5D%20===%20S%5B-1%5D%20&%20%5C%5C%20%5Cend%7Bmatrix%7D%5Cright.)


### 代码
```js
/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
  let res = new Array()
  for (let i = 0; i <= t.length; i++) {
    let tem = new Array(s.length + 1).fill(0)
    res.push(tem.slice())
  }

  for(let i = 0; i <= s.length; i++) {
    res[0][i] = 1
  }

  for (let i = 1; i <= t.length; i++) {
    for (let j = 1; j <= s.length; j++) {
      res[i][j] += res[i][j-1]
      if (t[i-1] === s[j-1]) {
        res[i][j] += res[i-1][j-1]
      }
    }
  }
  return res[t.length][s.length]
};
```