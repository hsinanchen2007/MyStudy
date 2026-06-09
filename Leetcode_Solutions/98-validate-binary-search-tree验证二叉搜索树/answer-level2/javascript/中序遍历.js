### 解题思路
中序遍历，先将左侧所有节点都放到数组中。 注： 所有子树都会进行这样的递归操作。
在全局搞一个tamp的临时变量，执行过判断以后，随时将current的value赋值给他。
这地方有两个判断，一个是根节点的value要大于左孩子节点的value ;二是当root = root.right的时候，下次判断的是右边要大于root 的value值。
对每一个的子树都要这样递归。

注：两个空判断，空树也是二查搜索树； 当输入的是[0] ，可以单独做一个标志，让他在循环中先走一遍

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
    if(root == null) {return true};
    let arr = []
    let isInit = false
    let temp = Number.MIN_VALUE;
    while(root!=null || arr.length !=0){
        while(root!=null){
            arr.push(root);
            root = root.left;
        }
        root = arr.pop();
        if(root.val <= temp && isInit){return false}
        isInit = true
        temp = root.val;
        root = root.right
    }
    return true
};
```