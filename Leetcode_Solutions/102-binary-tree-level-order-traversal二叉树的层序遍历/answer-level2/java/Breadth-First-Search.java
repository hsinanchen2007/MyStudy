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
    public List<List<Integer>> levelOrder(TreeNode root) {
        // 用来存储结果
        List<List<Integer>> resultList = new LinkedList<>();

        // root为null，返回空链表
        if(root == null)
            return resultList;

        // 存储每一层从左到右的节点值
        List<Integer> subList = new LinkedList<>();
        // 所有在queue中的node的值都是还没有存进sublist的
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        // 用null来分隔queue中的每一层
        queue.add(null);
        while(!queue.isEmpty()){
            TreeNode parent = queue.remove();
            // 如果为null，说明需要进入下一层了，为什么？
            if(parent == null){
                resultList.add(subList);
                subList = new LinkedList<>();
                // 只有在queue非null时，才需要sentinel
                if(!queue.isEmpty()){
                    queue.add(null);
                }
                continue;
            }

            subList.add(parent.val);
            if(parent.left != null)
                queue.add(parent.left);
            if(parent.right != null)
                queue.add(parent.right);
        }
        return resultList;
    }
}
```