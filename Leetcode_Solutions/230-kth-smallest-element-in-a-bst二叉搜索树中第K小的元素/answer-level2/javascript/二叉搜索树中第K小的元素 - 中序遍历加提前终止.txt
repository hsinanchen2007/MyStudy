### 解题思路
中序遍历加提前终止，思路见代码注释
![image.png](https://pic.leetcode-cn.com/af6bc25cb64a0f9ef247a8a73a9351e7339213e3c7bd45d4ca3f49f8288371dc-image.png)

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
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    let count = 0;
    let res = -1;
    // 中序遍历，何为中序？
    // 即遍历顺序为：node.left -> node -> node.right
    // 为什么可以这么做？
    // BST特征决定：节点 N 左子树上的所有节点的值都小于等于节点 N 的值
    //          :  节点 N 右子树上的所有节点的值都大于等于节点 N 的值
    function order(node) {
        if (!node) {
            return;
        }
        order(node.left); // 如果left 一直存在，则一直深度遍历left
        if(count >= k) { // 提前终止
            return;
        }
        if (node.val !== null) { // 遍历一次中序节点，则找到的当前值为第count大，只要不为count 大，需要继续遍历（上一句逻辑）
            res = node.val;
            count++;
        }
        order(node.right);

    }
    order(root);
    return res;
};
```