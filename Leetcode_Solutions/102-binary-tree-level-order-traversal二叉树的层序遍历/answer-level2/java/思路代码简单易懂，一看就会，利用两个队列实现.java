### 解题思路
如果不考虑分层输出，只是作简单的层序遍历那么我们只需要一个队列就能实现（网上很多教程），本题需要分层输出，这时我们只要增加一个队列同步记录入队节点的level值就可以解决了

两个队列，queue1存节点，queue2存节点所在level
根节点为空时直接返回
根节点不为空时,root节点入队queue1，同时root节点所在的level也就是0入队queue2
（两个队列都是同时操作，要么都入队一个值，要么都出队一个值，所以queue1出队的节点所处的level肯定是queue2出队的值）
用一个while循环将两个队列作出队处理
根据queue2出队的值，也就是当前节点的level值判断需不需要新建列表
只要当前节点左右子树不为空，则相应子树入队queue1，同时queue2入队的是当前节点level值+1
根据队列先进先出的特点我们就完成了遍历

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
        List<List<Integer>> res = new ArrayList<>();
        if (root != null) {
            Queue<TreeNode> queue1 = new LinkedList<>();
            Queue<Integer> queue2 = new LinkedList<>();
            queue1.offer(root);
            queue2.offer(0);
            while (!queue1.isEmpty()) {
                TreeNode node = queue1.poll();
                Integer level = queue2.poll();
                if (res.size() <= level) {
                    res.add(new ArrayList<>());
                }
                res.get(level).add(node.val);
                if (node.left != null) {
                    queue1.offer(node.left);
                    queue2.offer(level + 1);
                }
                if (node.right != null) {
                    queue1.offer(node.right);
                    queue2.offer(level + 1);
                }
            }
        }
        return res;
    }
}
```