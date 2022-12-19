### 解题思路

广度优先处理方式，使用队列，来处理，每次取出一个节点，都在队列后面放入其左子节点和右子节点（支持NULL）



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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        } else if (p == null) {
            return false;
        } else if (q == null) {
            return false;
        }
        if (p.val != q.val) {
            return false;
        }
        // 广度优先遍历原则，需要使用队列，其实就是链表
        LinkedList<TreeNode> pList = new LinkedList<>();
        LinkedList<TreeNode> qList = new LinkedList<>();

        pList.addLast(p);
        qList.addLast(q);

        while (!pList.isEmpty() && !qList.isEmpty()) {
            TreeNode pFirst = pList.removeFirst();
            TreeNode qFirst = qList.removeFirst();
            if (pFirst == null && qFirst == null) {
                continue;
            } else if (pFirst != null && qFirst == null) {
                return false;
            } else if (pFirst == null) {
                return false;
            }
            if (pFirst.val != qFirst.val) {
                return false;
            }
            pList.addLast(pFirst.left);
            pList.addLast(pFirst.right);
            qList.addLast(qFirst.left);
            qList.addLast(qFirst.right);
        }

        return pList.isEmpty() && qList.isEmpty();
    }
}
```