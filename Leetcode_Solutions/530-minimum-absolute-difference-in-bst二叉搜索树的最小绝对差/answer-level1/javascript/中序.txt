### 解题思路
此处撰写解题思路

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
var getMinimumDifference = function(root) {
    let preNode = null
    let min = Infinity
    let inOrderTravel = (root) =>{
        if(root){
            inOrderTravel(root.left)
            /*
            **中序是升序输出，每次记录上一个值
            */
            if(preNode != null){
                min = Math.abs(root.val - preNode.val) < min ? Math.abs(root.val - preNode.val) : min
            }
            preNode = root
            inOrderTravel(root.right)
        }
    }
    inOrderTravel(root)
    return min
};
```