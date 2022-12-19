### 解题思路
能不用递归就不用递归。
1. 原理：二叉树层次遍历
2. maxDepth表示最大深度（即二叉树层数），curPeerCnt表示当前层的结点数目，nxtPeerCnt表示下一层的结点数目
3. 根节点入队，curPeerCnt = 1，nxtPeerCnt = 0
4. 循环结点出队，curPeerCnt--，出队结点的左右子节点分别入队，入队时nxtPeerCnt++。
5. curPeerCnt减到0时，说明该层结点已全部出队，此时往下挪一层，maxDepth++，curPeerCnt = nxtPeerCnt，nxtPeerCnt = 0
5. 队列空时停止，maxDepth即为最大深度

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
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int maxDepth = 0;
        int curPeerCnt = 1; // 当前层的结点数目
        int nxtPeerCnt = 0; // 下一层的结点数目
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            curPeerCnt--;
            if (node.left != null ){
                q.add(node.left);
                nxtPeerCnt++;
            }
            if (node.right != null) {
                q.add(node.right);
                nxtPeerCnt++;
            }
            if (curPeerCnt == 0) {
                maxDepth++;
                curPeerCnt = nxtPeerCnt;
                nxtPeerCnt = 0; // 下一次层的结点数归0
            }
        }
        return maxDepth;
    }
}
```