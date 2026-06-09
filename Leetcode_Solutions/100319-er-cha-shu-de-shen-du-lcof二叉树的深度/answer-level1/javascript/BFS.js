### 解题思路
跟32题类似

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
 * @return {number}
 */
var maxDepth = function(root) {
    if(!root){
        return 0
    }
    const queue = [];
    queue.push(root);
    const res = [];
    while(queue.length >0){
        let temp = [];
        let len  = queue.length;
        for(let i = 0; i<len;i++){
            let nodes = queue.shift()
            temp.push(nodes.val);
            if(nodes.left){
                queue.push(nodes.left)
            }
            if(nodes.right){
                queue.push(nodes.right)
            }
        }
        res.push(temp)
    }

    return res.length
};
```