![image.png](https://pic.leetcode-cn.com/307c00fea281920a010b15c94c593777e4d010ae9c03c057a234dfc3aecb17d6-image.png)

### 解题思路
```js
两种情况：
n为偶数：返回 1 个 'a' 拼上 n - 1 个 'b'
n为奇数：返回 n 个 'a'
```

### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var generateTheString = function(n) {
  if (n % 2 !== 0) return new Array(n).fill('a').join('');
  return 'a' + new Array(n - 1).fill('b').join('')
};
```