### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    return n.toString(2).split('').reduce((t,n) => +t + +n)
};
```

```js
var hammingWeight = function(n) {
    return n.toString(2).replace(/0/g,'').length
};
```
