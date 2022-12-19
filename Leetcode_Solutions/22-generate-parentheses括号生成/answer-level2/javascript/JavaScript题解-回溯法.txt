### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let result = [];
    //left:当前左括号个数；right：当前右括号个数
    var trackback = function(left,right,track){
        //回溯的终止条件：字符串长度为2n
        if(track.length===n*2){
           result.push(track);
           return;
        }
        //当左括号个数小于n时，可以继续枚举左括号
        left<n && trackback(left+1,right,track+'(');
        //当右括号个数小于n且小于左括号（符合平衡状态）时，可以继续枚举右括号
        right<left && trackback(left,right+1,track+')');
    }
    trackback(0,0,"");
    return result;
};
```