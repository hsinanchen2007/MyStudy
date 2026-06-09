```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    let levelArr = [];
    let node = root;
    let i = 0;
    subLevel(root,0);
    function subLevel (node,level){
            if(node == null) return;
            if(!levelArr[level]) levelArr[level] = [];
            levelArr[level].push(node.val);
            if(node.left){
                subLevel(node.left,level+1);
            }
            if(node.right){
                 subLevel(node.right,level+1);
            }
    }
    return levelArr;
};

```