### 解题思路
- BigInt 是 JavaScript 最新的支持的数据类型
- 通过 添加 '' 自动转换成 string 数据格式

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number[]}
 */
var addToArrayForm = function(A, K) {
    let num = BigInt(A.join('')) + BigInt(K + '') + ''
    return num.split('')
};


```