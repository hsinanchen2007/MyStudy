
BFS遍历A,然后用dfs来判断当前节点是否存在该子结构
### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */
var isSubStructure = function(A, B) {
    if(B===null)return false;
    let qu=[A];
    while(qu.length>0){
        let cur=qu.shift();
        let flag=false;
        if(cur.val === B.val)flag=dfs(cur,B);
        if(flag)return flag;
        if(cur.left)qu.push(cur.left);
        if(cur.right)qu.push(cur.right);
    }

    function dfs( A,B){
        if(B===null)return true;
        if(A===null)return false
        if(A.val !== B.val)return false;
        return dfs(A.left,B.left) && dfs(A.right,B.right);
    }
    return false;

};
```