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
    if(!preorder || !inorder) {
        return null;
    }
    if (preorder.length === 0 || inorder.length === 0) {
        return null;
    }
    if (preorder.length === 1 && inorder.length === 1) {
        return new TreeNode(preorder[0]);
    }

    const map = {};
    let index = 0;
    for (let p of inorder) {
        map[p] = index++;
    }

    const root = new TreeNode(preorder[0]);
    const rootIndex = map[preorder[0]];

    function helper(node, pnodeIndex, inodeIndex, lowIndex, highIndex) {
        // 左边的节点个数
        const leftNodeCount = inodeIndex - lowIndex;
        if (leftNodeCount) {
            // 左
            // 左节点位置是当前节点先序遍历位置加1
            const leftIndex = pnodeIndex + 1;
            const left = new TreeNode(preorder[leftIndex]);
            node.left = left;
            // 找到中序遍历中，左节点位置
            const leftInorder = map[preorder[leftIndex]];
            // 遍历左树
            helper(left, leftIndex, leftInorder, lowIndex, inodeIndex - 1);
        }
        // 右边的节点个数
        const rightNodeCount = highIndex - inodeIndex;
        if (rightNodeCount) {
            // 右
            // 右节点位置是当前节点先序遍历位置加左边node的总数加1
            const rightIndex = pnodeIndex + leftNodeCount + 1;
            const right = new TreeNode(preorder[rightIndex]);
            node.right = right;
            // 找到中序遍历中，右节点位置
            const rightInorder = map[preorder[rightIndex]];
            // 遍历右树
            helper(right, rightIndex, rightInorder, inodeIndex + 1, highIndex);
        }
    }
    // 初始化
    // 当前节点为root，先序遍历中root在0， 中序遍历中root的位置，中序遍历的起始位置，中序遍历的结束位置
    helper(root, 0, rootIndex, 0, inorder.length - 1);
    return root;
};
```


![image.png](https://pic.leetcode-cn.com/e5226ca1762cf9860fd1b44b17d6532a45fa9887422eb6aea4717ad05f6674a9-image.png)
