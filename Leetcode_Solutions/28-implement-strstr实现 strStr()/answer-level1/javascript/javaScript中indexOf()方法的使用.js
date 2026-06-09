### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    return haystack.indexOf(needle)
};

let getSum = strStr("hello","ll")
let getSumTwo = strStr("hello","aa")
let getSumThree = strStr("hello","")

console.log(getSum) // 2
// console.log(getSumTwo) // -1
// console.log(getSumThree) // 0
```
引用 javaScript中的indexOf()的方法,寻找haystack中是否有needle中的索引,如果有的话,就返回第一个和needle字符串相同的索引,反之,没有的话将直接返回 -1。