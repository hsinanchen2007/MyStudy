### 解题思路
前序遍历的第一个数一定是根，在中序遍历中查找这个数值，这个数值将中序遍历划分为左右两个子树，得到这两个子树的前序遍历和中序遍历后再使用同样的方法。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return builder(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    public TreeNode builder(int[] preorder, int pFrom, int pTo, int[] inorder, int iFrom, int inTo) {
        if(pTo < pFrom || inTo < iFrom) {
            return null;
        }
        if(pTo == pFrom) {
            return new TreeNode(preorder[pFrom]);
        }
        TreeNode newNode = new TreeNode(preorder[pFrom]);
        int leftSize = 0;
        while(inorder[iFrom + leftSize] != preorder[pFrom]) {
            leftSize++;
        }
        int rightSize = pTo - pFrom - leftSize;
        if(leftSize > 0) {
            newNode.left = builder(preorder, pFrom + 1, pFrom + leftSize, inorder, iFrom, iFrom + leftSize - 1);
        }
        if(rightSize > 0) {
            newNode.right = builder(preorder, pTo - rightSize + 1, pTo, inorder, inTo - rightSize + 1, inTo);
        }
        return newNode;
    }
}
```