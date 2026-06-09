### 解题思路
按层BFS遍历，记录当前层的节点数，每出队列一个，数量-1，当数量为0的时候，表示当前层遍历完成，可以进入下一层

每一层遍历完成，只需要做3件事
1.链表的首元结点（代码里体现为head.next）加入结果集。
2.当前链表节点重置为head，准备进入下层。
3.当前层数量重置为队列长度。

最后进入下一层。

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
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode[] listOfDepth(TreeNode tree) {
        if (tree == null){
            return new ListNode[]{};
        }
        TreeNode tNode = tree;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(tNode);
        int rear = queue.size();
        
        List<ListNode> res = new ArrayList<>();
        ListNode head = new ListNode(0);
        ListNode LNode = head;
        while (!queue.isEmpty()){
            tNode = queue.poll();
            rear--;// 当前层-1
            // listNode节点处理
            LNode.next = new ListNode(tNode.val);
            LNode = LNode.next;
            // 左右节点入队列
            if (tNode.left != null){
                queue.offer(tNode.left);
            }
            if (tNode.right != null){
                queue.offer(tNode.right);
            }
            if (rear == 0){
                // 当前层遍历结束，全部ListNode加入
                res.add(head.next);
                // 链表节点重置到头部
                LNode = head;
                // 新一层的数量
                rear = queue.size();
            }
        }
        return res.toArray(new ListNode[res.size()]);
    }
}
```