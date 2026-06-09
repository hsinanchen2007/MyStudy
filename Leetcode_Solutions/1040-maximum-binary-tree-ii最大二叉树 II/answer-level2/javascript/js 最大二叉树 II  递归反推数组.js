1. 这道题是[654.最大二叉树](https://leetcode-cn.com/problems/maximum-binary-tree/)的进阶版，如果没做过这道题建议先做下这道
2. 题目有一些晦涩，首先搞懂最大二叉树是什么，最大二叉树的根节点是数组里最大的元素，左子树是数组最大元素左边的数组arr.slice(0, max)构成的最大二叉树，右子树是数组最大元素右的数组arr.slice(max+1)构成的最大二叉树，则左子树的根节点是数组arr.slice(0, max)的最大元素，以此类推，这是一个典型的递归
3. 题目中未给定数组A，给出的是由最大二叉树规则构造出的二叉树root，由root可以反推数组A
4. 找出A后，因为B是A的副本，且附加值val，则B是[...A, val]
5. 找出B后，根据654的算法即可得出最大二叉树啦
 
```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoMaxTree = function(root, val) {
    let maxFn = (arr) => {
        let max = arr[0]
        for(let i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i]
            }
        }
        return max
    }
    let fn = (root, arr) => {
        if (root === null) return []
        return [...fn(root.left), root.val, ...fn(root.right)]
    }
    let list = fn(root)
    let listB = [...list, val]
    let getRoot = (root, arr) => {
        if (arr.length === 0) return null
        let max = maxFn(arr)
        let idx = arr.indexOf(max)
        root.val = max
        root.left = getRoot(new TreeNode(), arr.slice(0, idx))
        root.right = getRoot(new TreeNode(), arr.slice(idx+1))
        return root
    }
    return getRoot(new TreeNode(), listB)
};
```
