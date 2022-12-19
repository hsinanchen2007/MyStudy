# 思路
1. 不是 `//` `.` `..` 则入栈`push`
2. 如果是`..` 且不是第一个也就是根目录，则出栈`pop`

# 代码
``` javascript
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
  const dirs = path.split('/')
  const stack = []

  for (let i = 0; i < dirs.length; i++) {
    const dir = dirs[i]

    if (dir && dir !== '.' && dir !== '..') {
      stack.push(dir)
    } else if (dir === '..' && i > 1) {
      stack.pop()
    }
  }

  return '/' + stack.join('/')
}
```
# 运行

![image.png](https://pic.leetcode-cn.com/e244c56cd1d3eabafc320a46f290166fbc03ce6db1306b1f79decdfe40551872-image.png)


