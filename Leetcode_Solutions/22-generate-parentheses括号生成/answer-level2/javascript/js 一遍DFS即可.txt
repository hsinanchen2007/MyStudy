### 解题思路
初始化字符串cur='(',left=1表示当前的左括号的数量,right=0当前的右括号的数量;执行df函数遍历
如果left>right 不符合条件退出
如果left===n 并且n===right表示当前字符串符合条件，将它push进res
选择在字符串后面添加左括号或者右括号，相应的left或者right加1，继续执行dfs

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    if(n===0) return [];
    let res=[]; //保存符合条件字符串的结果集
    function dfs(cur,left,right){
        if(left<right) return;
        if(left===n&&right===n){
            res.push(cur);
        }
        if(left<n)dfs(cur+'(',left+1,right);
        if(right<n)dfs(cur+')',left,right+1);
    }
    dfs('(', 1, 0); 
    return res;
};
```