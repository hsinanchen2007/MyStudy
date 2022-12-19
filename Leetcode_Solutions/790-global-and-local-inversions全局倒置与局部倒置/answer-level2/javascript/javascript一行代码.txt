### 解题思路

大家好，我是 17

这道题关键的是理解题意，然后做总结。
如果给数列先排个序
所谓的全局倒置就是 元素偏离正确位置` >= 1`
所谓的局部倒置就是 元素偏离正确位置` == 1`

所以如果全局倒置和局部倒置相等，只能 元素偏离正确位置` == 1`

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var isIdealPermutation = function(A) {
   return A.every((n,index)=>Math.abs(n-index)<=1)
};
```