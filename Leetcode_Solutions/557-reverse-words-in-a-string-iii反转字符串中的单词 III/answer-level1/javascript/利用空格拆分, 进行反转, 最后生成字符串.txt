```javascript []
return s.split(' ').map(item => {   // 字符串按空格进行分隔, 每一个单词作为数组一个值
    return item.split('').reverse().join('')    // 遍历数组, 将每个值进行 reverse()
  }).join(' ')  // 拼接数组, 以空格分隔
```
