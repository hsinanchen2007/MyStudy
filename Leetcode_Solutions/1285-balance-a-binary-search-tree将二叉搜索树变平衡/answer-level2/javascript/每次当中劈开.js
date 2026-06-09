### 解题思路
![image.png](https://pic.leetcode-cn.com/63f55adf9436c5c4625b705c7318a3f75fb8fc9413fa79543b603f2ee8c735fe-image.png)

序列化为数组，数组排序，当中劈开分左右树，再递归劈开。。。
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
 * @return {TreeNode}
 */
var balanceBST = function (root) {
    let treeArr = [];

    const travel = root => {
        if (root) {
            travel(root.left);
            treeArr.push(root.val);
            travel(root.right);
        }
    }
    travel(root);
    treeArr.sort((a, b) => a - b);
    console.log(treeArr);

    const buildTree = arr => {
        if (arr.length === 0) return null;
        if (arr.length === 1) return new TreeNode(arr[0]);

        let len = arr.length,
            mid = Math.floor(len / 2)
        midVal = arr[mid];

        let balanceTree = new TreeNode();
        balanceTree.val = midVal;
        let leftArr = arr.slice(0, mid);
        balanceTree.left = buildTree(leftArr);

        let rightArr = arr.slice(mid + 1, len);
        balanceTree.right = buildTree(rightArr);
        return balanceTree;
    }
    return buildTree(treeArr);
};
```