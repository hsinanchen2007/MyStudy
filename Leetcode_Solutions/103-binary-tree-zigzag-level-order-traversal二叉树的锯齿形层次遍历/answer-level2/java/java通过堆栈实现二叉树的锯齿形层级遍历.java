 **思路**
采用两个堆栈popStack、pushStack，其中popStack存储当前遍历层级的节点信息，pushStack存储下一层级遍历的节点信息，且奇数层级从右往左依次入栈，偶数层级从左往右依次入栈。

**实现代码**

```java
package leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * @Description: leetcode_103
 * @Date: 2020-04-04 00:50:03
 */
public class leetcode_103 {

    public static void main(String[] args) {
        Integer[] array = new Integer[]{1, 2, 3, 4, 5, 6, 7,8,9,10,11,12,13,14,15};
        TreeNode node = builderTreeNode(array);
        List<List<Integer>> lists = zigzagLevelOrder(node);
        System.err.println("finish");
    }

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> lists = new ArrayList<>();
        LinkedList<TreeNode> popStack = new LinkedList<>(), pushStack = new LinkedList<>();
        popStack.push(root);
        int level = 0;
        List<Integer> childList = new ArrayList<>();
        TreeNode node = null;
        do {
            if (!popStack.isEmpty()) {
                node = popStack.pop();
                if (null != node) {
                    childList.add(node.val);
                    if (level % 2 == 0) {
                        left2Right(node, pushStack);
                    } else {
                        right2left(node, pushStack);
                    }
                }
            } else {
                if (childList.size() == 0) {
                    break;
                }
                LinkedList<TreeNode> tempStack = pushStack;
                pushStack = popStack;
                popStack = tempStack;
                level++;
                lists.add(childList);
                childList = new ArrayList<>();

            }
        } while (true);
        return lists;
    }

    /**
     * left t0 right direction
     *
     * @param parentNode
     * @param stack
     */
    private static void right2left(TreeNode parentNode, LinkedList<TreeNode> stack) {
        if (null != parentNode.right) {
            stack.push(parentNode.right);
        }
        if (null != parentNode.left) {
            stack.push(parentNode.left);
        }

    }

    /**
     * right to left direction
     *
     * @param parentNode
     * @param stack
     */
    private static void left2Right(TreeNode parentNode, LinkedList<TreeNode> stack) {
        if (null != parentNode.left) {
            stack.push(parentNode.left);
        }
        if (null != parentNode.right) {
            stack.push(parentNode.right);
        }
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