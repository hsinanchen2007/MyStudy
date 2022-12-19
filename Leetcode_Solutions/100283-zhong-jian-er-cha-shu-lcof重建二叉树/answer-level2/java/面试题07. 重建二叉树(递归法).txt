### 解题思路
见注释，主要求得前序根节点在中序的位置，使用辅助map，再利用中序中根节点所在位置求出左右子树节点的范围。最后递归即可

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
        if (preorder == null || preorder.length == 0) {
            return null;
        }
        Map<Integer, Integer> indexMap = new HashMap<Integer, Integer>();
        int length = preorder.length;
        for (int i = 0; i < length; i++) {
            indexMap.put(inorder[i], i);
        }
        TreeNode root = buildTree(preorder, 0, length - 1, inorder, 0, length - 1, indexMap);
        return root;
    }

     public TreeNode buildTree(int[] preorder, int preorderStart, int preorderend, int[] inorder, int inorderstart, int inorderend, Map<Integer,Integer> map){
        if(preorderStart>preorderend){
            return null;
        }
        int rootValue=preorder[preorderStart];//前序第一个值为根节点值
        TreeNode root=new TreeNode(rootValue);//创建二叉树
        if (preorderStart != preorderend) {
            int rootIndex = map.get(rootValue);//获取根节点在中序的位置
            int leftNodes = rootIndex - inorderstart;//左子树的范围
            int rightNodes = inorderend - rootIndex;//右子树的范围
            TreeNode leftSubTree = buildTree(preorder, preorderStart + 1, preorderStart + leftNodes, inorder, inorderstart, rootIndex - 1, map);
            TreeNode rightSubTree = buildTree(preorder, preorderend - rightNodes + 1, preorderend, inorder, rootIndex + 1, inorderend, map);//构造右子树
            root.left = leftSubTree;
            root.right = rightSubTree;
        }
        return root;
    }
}

```