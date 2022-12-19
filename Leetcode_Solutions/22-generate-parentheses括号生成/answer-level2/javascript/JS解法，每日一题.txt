### 解题思路
题目要求所有括号都为闭合的括号，说明排列组合的过程中，
每一个下标之前，左括号一定不比右括号少，且数量都小于等于n。
有了条件，进行递归计算即可。

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let str=[];
    let fun=(s,l,r)=>{
        if(l===n&&r===n) return str.push(s)
        if(l<n) fun(s+'(',l+1,r)
        if(r<l) fun(s+')',l,r+1)
    }
    fun('', 0, 0)
    return str
};
```