### 解题思路
虽然简洁，但可读性差，不推荐这么写。看懂代码需要一些前置知识，我列在下方：
1. 数组遍历map()方法
2. 数组反转reverse()方法
3. ES6箭头函数()=>{}，单一参数与单行执行语句可省略括号
4. 0-1反转等价于异或操作(0^1=1;1^1=0)

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    return A.map(arr=>arr.map(item=>item^1).reverse())
};
```