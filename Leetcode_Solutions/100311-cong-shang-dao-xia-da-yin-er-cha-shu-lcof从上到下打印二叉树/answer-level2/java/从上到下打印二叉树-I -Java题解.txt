### 解题思路
树的广度优先遍历（BFS）
利用队列和list集合，
1. 把队列的头取出且其值val添加到list集合中。
2. 若队头节点有孩子节点，将他们添加到队列，返回上一步
3. 重复此操作，直至队列为空说明遍历完毕。
4. 最后创建数组存储list集合中的元素作为返回值

时间复杂度：O(N) -取决于二叉树的节点数量 N，即while循环 N 次。
空间复杂度：O(N) -最差情况下，即当树为 平衡二叉树 时，最多同时有 N/2 个节点在队列中。

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
    public int[] levelOrder(TreeNode root) {
        if(root == null) return new int[0];

        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        q.offer(root);
        
        while(!q.isEmpty()){
            TreeNode node = q.poll();
            list.add(node.val);
            if(node.left != null) q.offer(node.left);
            if(node.right != null) q.offer(node.right);
        }
        
        int[] res = new int[list.size()];
        for(int i = 0;i < list.size();i++){
            res[i] = list.get(i);
        }
        return res;

    }
}
```