![image.png](https://pic.leetcode-cn.com/23f8af64dbee5666b8a9017d922757031ad3d0d47094692a85841d242ed348cb-image.png)

### 解题思路
约瑟夫环

### 代码
模拟超时
```JavaScript
var lastRemaining = function(n, m) {
  let arr = []
  for (let i = 0; i < n; ++i) {
    arr.push(i)
  }
  let index = -1
  while (arr.length > 1) {
    for (let j = 0; j < m; ++j) {
      ++index
      if (index === arr.length) {
        index = 0
      }
    }
    arr.splice(index, 1)
    --index
  }
  return arr[0]
};
```

```JavaScript
var lastRemaining = function(n, m) {
  let f = 0
  for (let i = 1; i <= n; i++) {
    f = (f + m) % i 
  }
  return f
};
```