### 解题思路
注意，这道题是子结构，不是子树。解法和子树差不多，唯一不同的就是子结构只要匹配一部分就可以 

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
    if(!B) return false
    function check(t1,t2){
        if(!t1&&!t2) return true
        //如果是子树这里返回 false
        if(!t2) return true
        if(!t1) return false
        if(t1.val!==t2.val) return false
        return check(t1.left,t2.left)&&check(t1.right,t2.right)
    }
    let isSame=false
    function helper(root){
        if(!root||isSame===true) return

        if(check(root,B)){
            isSame=true
            return
        }
        helper(root.left)
        helper(root.right)
    }
    helper(A)
    return isSame
};
```