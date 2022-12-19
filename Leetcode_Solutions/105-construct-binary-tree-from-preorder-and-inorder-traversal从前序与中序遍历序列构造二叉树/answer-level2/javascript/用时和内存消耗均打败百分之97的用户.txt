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
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    let preIndex = 0
    function buildNode(left,right){
      if(left == right) {
        return null
      }
      let value = preorder[preIndex]
      let node = new TreeNode(value);

      let index = inorder.indexOf(value)

      preIndex++

      node.left = buildNode(left,index)
      node.right = buildNode(index+1, right)
      return node
    }

    return buildNode(0,inorder.length)
};

```