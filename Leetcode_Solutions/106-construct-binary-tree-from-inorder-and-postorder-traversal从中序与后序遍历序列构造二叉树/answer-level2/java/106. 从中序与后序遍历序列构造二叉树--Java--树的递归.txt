### 解题思路
[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_106_buildTree.java)

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
    /**
     * 解题思路：
     * 中序：左->中->右，后序：左->右->中
     * 1、取后序的最后一位就是根节点
     * 2、遍历中序，找到根节点在中序中的位置I，I左边的就是左子树，右边就是右子树
     * 3、分别取中序和后续的0-I位置，得到的就是左子树的中序和后续遍历接通，重复步骤1、2将左子树构造出来
     * 4、同理步骤3，将右子树构造出来
     *
     * @param inorder
     * @param postorder
     * @return
     */
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0) return null;
        int rootVal = postorder[postorder.length - 1];
        TreeNode rootNode = new TreeNode(rootVal);
        int rootIndex = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == rootVal){
                rootIndex = i;
                break;
            }
        }
        rootNode.left = buildTree(Arrays.copyOfRange(inorder, 0, rootIndex), Arrays.copyOfRange(postorder, 0, rootIndex));
        rootNode.right = buildTree(Arrays.copyOfRange(inorder, rootIndex + 1, inorder.length), Arrays.copyOfRange(postorder, rootIndex, postorder.length - 1));
        return rootNode;
    }
}
```