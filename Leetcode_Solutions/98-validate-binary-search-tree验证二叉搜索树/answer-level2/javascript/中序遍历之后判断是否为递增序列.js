### 解题思路
先进行中序遍历，然后判断中序遍历的数组是否是递增序列

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
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
    var res = [];
    var stack = [];
    while(root!=null||stack.length!=0){
        while(root!=null){
            stack.push(root);
            root=root.left;
        }
        root = stack.pop();
        res.push(root.val);
        root = root.right;
    }
    var flag=true;
    for(var i=0;i<res.length-1;i++ ){
        if(res[i]>=res[i+1]){
            flag=false;
            break;
            }
    }
    return flag;
};
```