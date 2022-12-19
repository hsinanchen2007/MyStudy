### 解题思路
层次遍历，如果节点是偶数，就将其孙子节点的和相加。

这里判断是否偶数用了个位运算，就是为了更快一点。其他的基本就是标题上的话了，这题不难。

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
    public int sumEvenGrandparent(TreeNode root) {
        int sum = 0;
        TreeNode node = root;
        // 层次遍历树
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(node);
        while (!queue.isEmpty()){
            node = queue.poll();
            // 节点值是偶数
            boolean isEven = (node.val & 1) == 0;
            if (node.left != null){
                queue.offer(node.left);    
                if (isEven){
                    // 左孩子的孩子节点和加入
                    sum += childNodeSumValue(node.left);
                }
            }
            if (node.right != null){
                queue.offer(node.right);
                if (isEven){
                    // 右孩子的孩子节点和加入
                    sum += childNodeSumValue(node.right);
                }
            }
        }
        return sum;
    }

    /**
     * 孩子节点和
     * @param node treeNode
     * @return 孩子节点和
     */
    private int childNodeSumValue(TreeNode node){
        int childSum = 0;
        if (node.left != null){
            childSum += node.left.val;
        }
        if (node.right != null){
            childSum += node.right.val;
        }
        return childSum;
    }
}
```