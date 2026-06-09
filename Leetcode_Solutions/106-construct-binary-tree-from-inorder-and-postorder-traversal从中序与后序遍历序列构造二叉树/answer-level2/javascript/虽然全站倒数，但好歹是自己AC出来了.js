### 解题思路
![image.png](https://pic.leetcode-cn.com/76fb85fc3f6f090a2eb444d544ad3e1ec26e93311c9e42730f41d6e5f6063ce8-image.png)

思路不难，就是根据“后序数组确定根，由根把中序数组一劈二，左边是左子树，右边是右子树，再分别用中序劈开后的左右两段去后序数组中截取左右子树的后序数组（一定要保持原来的顺序截取出来），然后递归构建左右子树。

踩了个坑，array.sort()默认的话，会把10，11，12排在8，9前面，一定要写完整！
`array.sort(function (a, b) { return a - b; });`

最后附上test case中的一棵参天大树，哈哈！
![image.png](https://pic.leetcode-cn.com/14505c9a3d85e97f595e4be365243692c5131030f37896d09a105ccc79c4a704-image.png)


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
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function (inorder, postorder) {
    if (inorder.length === 0 || postorder.length === 0) return null;

    let root = new TreeNode(postorder[postorder.length - 1]),
        rootIdx = inorder.indexOf(root.val),
        leftInOrder = [],
        rightInOrder = [],
        leftPostOrder = [],
        rightPostOrder = [],
        valIdx = [];

    for (let i = 0; i < rootIdx; i++) {
        leftInOrder.push(inorder[i]);
        valIdx.push(postorder.indexOf(inorder[i]));
    }
    valIdx.sort(function (a, b) { return a - b; });
    for (let i in valIdx) {
        leftPostOrder.push(postorder[valIdx[i]]);
    }

    valIdx = [];
    for (let i = rootIdx + 1; i < inorder.length; i++) {
        rightInOrder.push(inorder[i]);
        valIdx.push(postorder.indexOf(inorder[i]));
    }
    valIdx.sort(function (a, b) { return a - b; });
    for (let i in valIdx) {
        rightPostOrder.push(postorder[valIdx[i]]);
    }

    if (leftInOrder.length != 0) root.left = buildTree(leftInOrder, leftPostOrder);
    if (rightInOrder.length != 0) root.right = buildTree(rightInOrder, rightPostOrder);

    return root;
};

```