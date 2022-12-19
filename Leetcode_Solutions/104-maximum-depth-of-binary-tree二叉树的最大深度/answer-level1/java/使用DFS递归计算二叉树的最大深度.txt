
**思路**

使用DFS(深度优先搜索)，递归遍历节点的左右子节点，若左节点的深度大于右节点的深度，则当前节点的最大深度为：currentDepth+ leftChildDepth, 反之，currentDepth+ rightChildDepth。

**实现代码**

```java

package leetcode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @Description: leetcode 104
 * @Date: 2020-04-04 16:25:06
 */
public class leetcode_104 {


    public static void main(String[] args){
        Integer[] array = new Integer[]{1, 2, 3, null, null, 4, 5,null, null, 6, 7,
                null, null, 8, 9, null, null,  null, 10};
        TreeNode node = builderTreeNode(array);
        System.err.println(maxDepth(node));
    }

    /**
     * calculate max depth of tree node
     *
     * @param root
     * @return
     */
    public static int maxDepth(TreeNode root) {
        if (null == root){
            return 0;
        }
        int depth = 1;
        //calculate depth of left child node
        int leftDepth = maxDepth(root.left);
        //calculate depth of right child node
        int rightDepth = maxDepth(root.right);
        if (rightDepth < leftDepth){
            depth +=leftDepth;
        }else {
            depth +=rightDepth;
        }
        return depth;
    }

    /**
     * builder tree node
     *
     * @param array
     * @return
     */
    private static TreeNode builderTreeNode(Integer[] array) {
        if (null != array && array.length != 0) {
            TreeNode rootNode = new TreeNode(array[0]);
            Queue<TreeNode> queue = new LinkedList<>();
            ((LinkedList<TreeNode>) queue).addLast(rootNode);
            for (int i = 0; i < array.length; ) {
                if (!queue.isEmpty()) {
                    TreeNode node = ((LinkedList<TreeNode>) queue).pollFirst();
                    if (++i < array.length && array[i] != null) {
                        node.left = new TreeNode(array[i]);
                        ((LinkedList<TreeNode>) queue).addLast(node.left);
                    }
                    if (++i < array.length && array[i] != null) {
                        node.right = new TreeNode(array[i]);
                        ((LinkedList<TreeNode>) queue).addLast(node.right);
                    }
                }
            }
            return rootNode;
        } else {
            return null;
        }
    }
    

    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            this.val = x;
        }
    }
    
}

```