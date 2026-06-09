### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function(left, right) {
  let list = []
  for(let i = left;i<=right;i++){
    let item = (i+'').split('')
    let flag = item.every(t => {  // every()是对数组中每一项运行给定函数，如果该函数对每一项返回true,则返回true。
      return i%t == 0
    })

    flag&&list.push(i)
  }
  return list
};
```