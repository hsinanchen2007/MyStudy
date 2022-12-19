### 解题思路
##### 遍历所有紧邻的两个括号，存在三种情况：
 1.  “（（”,则右括号比左边的深度+1
 2.  “））”,则右括号比左边的深度-1
 3. “（ ）”与“）（”,两者情况相同，深度不变
##### 将深度用数组表示，将超过深度一半的括号移除即可
##### 用0/1表示当前括号是否移除
![截屏2020-04-01 上午1.03.54.png](https://pic.leetcode-cn.com/a5ba55274bfd3505233cb3e3a99e9ace54e6fed2b87b53cd6f1e175da89e003e-%E6%88%AA%E5%B1%8F2020-04-01%20%E4%B8%8A%E5%8D%881.03.54.png)

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function (seq) {
  let res = [1];
  let max = 0;
  for (let i = 1; i < seq.length; i++) {
    if (seq[i - 1] === '(' && seq[i] === '(') {
      res[i] = res[i - 1] + 1
    } else if (seq[i - 1] === ')' && seq[i] === ')') {
      res[i] = res[i - 1] - 1
    } else {
      res[i] = res[i - 1]
    }
    max = Math.max(max, res[i])
  }
  let halfMax = parseInt(max / 2);
  res = res.map(item => {
    return item > halfMax ? 1 : 0
  })
  return res
};
```