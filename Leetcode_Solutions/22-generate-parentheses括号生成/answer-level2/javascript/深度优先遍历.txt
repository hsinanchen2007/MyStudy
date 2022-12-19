### 解题思路
深度优先遍历，用val标记当前累加值，遇到'('+1，遇到')'-1，最终结果一定是0才行。
遍历过程中，若val<0或val>n，不合法。

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var res = [];
    if(n == 0){
        return res;
    }

    //first one must be '(', last one must be ')'.
    dfs('(', n, 0, '', res);
    return res;
};

/**
 * @param {string} parent
 * @param {number} n
 * @param {number} val
 * @param {string} currStr
 * @param {string[]} res
 */
var dfs = function(parent, n, val, currStr, res){
    val += (parent == '(') ? 1 : -1;
    if(val > n || val < 0){
        return;
    }
    var tmpStr = parent == '(' ? (currStr + '(') : (currStr + ')');
    if(tmpStr.length == 2*n){
        if(val == 0){
            res.push(tmpStr);
        }
        return;
    }
    dfs('(', n, val, tmpStr, res);
    dfs(')', n, val, tmpStr, res);
};
```