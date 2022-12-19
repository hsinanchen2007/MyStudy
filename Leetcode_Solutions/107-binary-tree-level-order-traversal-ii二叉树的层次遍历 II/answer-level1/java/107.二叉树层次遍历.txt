### 解题思路
1、将节点值按层取出，放入层级链表
2、层级链表用头插法放入ans中，保障了返回值的顺序

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<>();
        if (root == null) {
            return ans;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            //存储当前层的节点val
            List<Integer> level = new LinkedList<>();
            int len = q.size();
            for(int i = 0;i < len;i++){
                TreeNode treeNode = q.poll();
                level.add(treeNode.val);
                //如果节点有孩子，则把他们也加入队列，在下一次循环中放入下一个level列表
                if (treeNode.left != null){
                    q.add(treeNode.left);
                }
                if(treeNode.right != null){
                    q.add(treeNode.right);
                }
            }
            //将整个一层的节点值按头插法放入
            ans.add(0,level);
        }
        return ans;
    }
}
```