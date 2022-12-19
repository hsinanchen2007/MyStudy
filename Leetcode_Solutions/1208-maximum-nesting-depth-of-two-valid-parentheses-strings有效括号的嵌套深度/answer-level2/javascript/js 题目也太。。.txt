![image.png](https://pic.leetcode-cn.com/cb9391af1e6ff06b9f9fc360304515a44fe73d29df2f360f38e10891a2ee65fc-image.png)

### 解题思路
```js
  题目也是真难读
  将 seq 分为 A 和 B 两个子序列，他们不相交，（注意：子序列可以是不连续的）

  返回的答案中：
    让属于 A 的括号下标为 0
    让属于 B 的括号下标为 1

  那么:
    给 A 分配一个左括号，然后给 B 分配一个左括号
    给 A 分配一个右括号，然后给 B 分配一个右括号
  这样保证 A 和 B 的括号的深度尽可能相等
```

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */

var maxDepthAfterSplit = function(seq) {
  let ans = [], left = 0, right = 0;
  
  for (let i = 0; i < seq.length; i++) {
    let c = seq.charAt(i);
    if (c === '(') {
      if (left === 0) {
        ans.push( 0 );
        left = 1;
      } else {
        ans.push( 1 );
        left = 0;
      }
    } else {
      if (right === 0) {
        ans.push( 0 );
        right = 1;
      } else {
        ans.push( 1 );
        right = 0;
      }
    }
  }
  
  return ans;
};
```