复习一下二叉树的特点，二叉树就像一棵树一样，从顶部向下延伸，最顶端的是根节点，每个节点下最多有两个子节点，没有子节点的节点叫做叶子节点，根节点和叶子节点中间的是中间节点。

因为两个都是二叉搜索树，每个节点的左子节点比自身小，右子节点比自身大，因此中序遍历一定是升序的。

1. 中序遍历获得两个升序数组，直接合并两个数组再使用 js 自带的 sort 方法排序。但是这种方法没有发挥出中序遍历的优势，合并后还要重新排序，用时和内存消耗分别是 316 ms	54.8 MB
```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {number[]}
 */
var getAllElements = function(root1, root2) {
    const getNode = (tree, arr = []) => {
        if (tree) {
            getNode(tree.left, arr)
            arr.push(tree.val)
            getNode(tree.right, arr)
        }
        return arr
    }
    return [...getNode(root1), ...(getNode(root2))].sort((i, j) => i - j)
};
```


2. 因为中序遍历获得的两个数组已经是升序排列的，可以使用归并排序合并两个数组，相较于sort方法效率更高，用时和内存消耗分别是 292 ms	54.6 MB
 ```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {number[]}
 */
var getAllElements = function(root1, root2) {
    let arr = []
    const getNode = (tree, arr = []) => {
        if (tree) {
            getNode(tree.left, arr)
            arr.push(tree.val)
            getNode(tree.right, arr)
        }
        return arr
    }
    let arr1 = getNode(root1)
    let arr2 = getNode(root2)
    for(let i = 0, j = 0; arr1.length > 0 && arr2.length > 0;) {
        let ele1 = arr1[0]
        let ele2 = arr2[0]
        if (ele1 > ele2) {
            arr.push(arr2.shift())
        } else {
            arr.push(arr1.shift())
        }
    }
    return [...arr, ...arr1, ...arr2]
}
```
