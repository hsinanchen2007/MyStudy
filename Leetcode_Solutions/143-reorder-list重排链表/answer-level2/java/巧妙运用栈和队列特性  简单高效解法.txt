### 解题思路
1、遍历链表。将各节点放入栈（后进先出）、队列中（先进先出）。
2、根据栈、队列的特性。开始在原链表上重新构建，从队列和栈交替取出元素。
3、重新构建的链表长度等于原链表长度 结束循环
4、由于新构建的链表的末节点是原链表的中心节点 所以末节点的next置为null。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        ListNode node = head;
        ListNode head_zero = new ListNode(0);
        Stack<ListNode> stack = new Stack<>();
        Queue<ListNode> queue = new LinkedList<>();
        //将节点放入栈和队列中
        while (node != null){
            stack.push(node);
            queue.add(node);
            node = node.next;
        }
        int size = stack.size();
        int count = 0;

        //构建链表 直到长度count等于原链表长度
        while (count < size){
            head_zero.next = queue.poll();
            head_zero = head_zero.next;
            if (++count == size){
                break;
            }
            head_zero.next = stack.pop();
            head_zero = head_zero.next;
            count++;
        }

        //新构建的链表的末节点为原链表的中心节点 所以需要把next置为null
        head_zero.next = null;
    }
}
```