### 解题思路
观察Z字形布局，字符串以类似L型重复，得出位置队列长度为 2n-2
定义数组，索引对应字符取余，值为字符对应位置
通过两次循环插入字符
时间复杂度 为O**(n + 2n -2)**
数组fill方法可以忽略不计

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows === 1) return s
const arr = new Array(numRows).fill('')
  let size = 2 * numRows - 2
  let i = 0
  let position = []
  for (i; i < size; i++) position.push(i < numRows ? i : position[i - 1] - 1)
  i = 0
  for (i; i < s.length; i++) arr[position[i % size]] += s[i]
  return arr.join('')
};
```