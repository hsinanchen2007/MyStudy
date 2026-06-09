### 解题思路
此处用的是广度优先解决
一层一层的遍历，每处理一层，将level + 1

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
    if(root == null){return 0}
    let quene = []
    quene.push(root)
    let level = 0;
    while(quene.length){
        let size = quene.length
        ++level
        for(let i =0; i< size; i++){
            let node = quene.shift()
            if(node.left){
                quene.push(node.left)
            }
            if(node.right){
                quene.push(node.right)
            }
        }
    }
    return level
};
```