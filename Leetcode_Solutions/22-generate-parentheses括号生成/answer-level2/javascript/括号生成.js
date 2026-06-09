### 一、深度优先搜索
#### 减法
- 可以生出左枝的条件是: 左括号的数量大于0
- 可以生出又支的条件是: 右括号的数量大于0并且左括号的数量小于右括号的数量
```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let ans = [];
    if(n==0) return ans;
    dfs('',n,n,ans);
    return ans;
};
const dfs = function(str,left,right,ans) {
    if(left=== 0 && right === 0) {
        ans.push(str);
        return;
    }
    if(left > right) return;
    if(left > 0) {
        dfs(str+'(',left-1,right,ans);
    }
    if(right > 0) {
        dfs(str+')',left,right-1,ans);
    }
}
```
#### 加法
```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let ans = [];
    if(n==0) return ans;
    dfs('',0,0,ans,n);
    return ans;
};
const dfs = function(str,left,right,ans,n) {
    if(left=== n && right === n) {
        ans.push(str);
        return;
    }
    if(left < right) return;
    if(left < n) {
        dfs(str+'(',left+1,right,ans,n);
    }
    if(right < n) {
        dfs(str+')',left,right+1,ans,n);
    }
}
```
### 二、广度优先搜索
```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
class Node {
    constructor(left,right,res) {
        this.left = left;
        this.right = right;
        this.res = res;
    }
}
var generateParenthesis = function(n) {
    let ans = [];
    if(n==0) return ans;
    let queue = [];
    queue.push(new Node(n,n,''));
    while(queue.length) {
        let node = queue.shift();
        if(node.left === 0 && node.right === 0) {
            ans.push(node.res);
        }
        if(node.left > 0) {
            queue.push(new Node(node.left-1,node.right,node.res +'('));
        }
        if(node.right > 0 && node.left < node.right) {
            queue.push(new Node(node.left,node.right-1,node.res +')'));
        }
    }
    return ans;
};
```