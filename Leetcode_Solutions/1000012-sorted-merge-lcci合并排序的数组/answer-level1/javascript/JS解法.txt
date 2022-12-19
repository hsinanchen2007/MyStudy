### 解题思路
需要注意的是直接操作A，不需要return。
操作A数组，按要求截取，并添加截取B数组后的元素，返回A（splice方法，...为es6的扩展运算符）；
对A进行数字大小排序（需要添加函数，否则按照字符编码排序）。

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    A.splice(m,A.length-m,...B.slice(0,n))
    A.sort((a,b)=>{return a-b})
};
```