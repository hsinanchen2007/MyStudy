### 解题思路
今天第一天开始训练，没有什么头绪。一开始想到的也是递归反方。
其实就是把括号推入字符串的递归过程。在中途可以判断左右节点，如果左节点数量少于右节点的话。
则可以直接判定为非法字符串，没有再执行下去的必要了。因为排除了非法情况，那么当left=0和right=0时
走到这一步的组合必定能满足需求。

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */

var generateParenthesis = function(n){
    const result = [];
    dfs(n,n,'',result);
    return result;
}


function dfs(left,right,str,result){
    if(left > right){
        return 
    }
    if(left === 0 && right ===0){
        result.push(str)
    }else{
        if(left> 0){
            dfs(left-1,right,str+'(',result)
        }
        if(right > 0) {
            dfs(left,right-1,str+')',result)
        }
    }
}
```