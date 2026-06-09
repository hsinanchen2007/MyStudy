### 解题思路
层序遍历二叉树，遍历的过程中保存最大值

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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        LinkedList<TreeNode> linkedList = new LinkedList<>();   //保存每层的节点
        linkedList.addFirst(root);
        while (!linkedList.isEmpty()) {
            int max = Integer.MIN_VALUE;    //保存最大值
            int size = linkedList.size();   //size表示上一层节点的数目
            for (int i = 0;i < size;i++) {  //遍历上层节点（在此过程中，每个节点的值与最大值做比较，并将下层节点添加进来）
                TreeNode node = linkedList.pollLast();
                if (node.val > max) {   //如果节点的值大于max，更新max
                    max = node.val;
                }
                if (node.left != null) {    //将左节点添加到linkedList中
                    linkedList.addFirst(node.left);
                }
                if (node.right != null) {   //将右节点添加到linkedList中
                    linkedList.addFirst(node.right);
                }
            }
            result.add(max);    //将该层的最大值保存到结果中
        }
        return result;
    }
}
```