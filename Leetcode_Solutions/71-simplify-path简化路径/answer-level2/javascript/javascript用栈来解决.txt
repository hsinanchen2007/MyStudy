```
/**
 * 将字符串按/分割为数组，过滤掉空格元素
 * 然后遍历数组，将 . .. 作为操作符，遇到.忽略，遇到..则操作数出栈
 * 时间复杂度O(2n) filter + loop
 * 空间复杂度O(1) 辅助数组和栈
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
  let arr = path.split('/').filter(c => c !== '') // 将字符串分割为数组，并过滤掉空格
  let stack = [] // 用数组模拟栈
  for (let c of arr) {
    if (c === '.' || c === '')
      continue
    else if (c === '..')
      stack.pop()
    else
      stack.push(c)
  }
  return `/${stack.join('/')}`
};
```
