### 解题思路
很简单,根据题目意思,用代码翻译过来就行了. Math的方法总是记不牢,这里使用一下加深记忆,计算一个数的多少次幂用Math.pow(number, 多少次幂), 平方根是Math.sqrt(number)

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
    return A.map(item=> Math.pow(item, 2)).sort((a,b)=>a-b)
};
```