### 解题思路
先用hashmap存好中序遍历的所有值对应其索引。
递归左右两颗子树， 只需要将左右子树分别在前序和中序数组中的开始和结尾点算出来即可。

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
    private TreeNode buildTree_help(int[] preorder, int[] inorder, int start1, int end1, int start2, int end2){
        if (start1 > end1){
            return null;
        }
        if (start1 == end1){
            return new TreeNode(preorder[start1]);
        }
        TreeNode node = new TreeNode(preorder[start1]);
        int in_idx = idx_map.get(preorder[start1]);
        node.left = buildTree_help(preorder, inorder, start1+1, start1+in_idx-start2, start2, in_idx-1);
        node.right = buildTree_help(preorder, inorder, start1+in_idx-start2+1, end1, in_idx+1, end2);

        return node;
    }

    HashMap<Integer, Integer> idx_map = new HashMap<>();
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length - 1;
        for (int i = 0; i <= n; i++){
            idx_map.put(inorder[i], i);
        }
        return buildTree_help(preorder, inorder, 0, n, 0, n);
    }
}
```