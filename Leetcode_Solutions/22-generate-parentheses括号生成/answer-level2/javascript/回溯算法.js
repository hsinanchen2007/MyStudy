### 解题思路
终止条件是：
- 左右括号都用完，拼接完成
- 左括号或者右括号用多了，不成立抛弃(`left < 0 || right < 0`)
- 左括号用的没有右括号多，不成立抛弃(比如`())`)

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = []
    function backtrack(left,right,str){
        if(!left && !right)
            return result.push(str)
        if(left < 0 || right < 0 || left > right) return 
        backtrack(left - 1,right,str+'(')
        backtrack(left,right - 1,str+')')
    }
    backtrack(n,n,'')
    return result
};
```