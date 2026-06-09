### 解题思路
因此次数的链表没有头结点，故删除结点应该想办法找到被删除结点的前一个结点，然后将前一个结点的next指向下下个结点达到删除的目的，由于ListNode类没有length的字段，因此我就先写了一个函数，确定被删除结点的前驱节点的位置，然后遍历确定位置再删除

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
  public ListNode deleteNode(ListNode head, int val) {

        //得到被删除结点的前一个位置
        int i = searchNode(head, val);
        int index = 1;
        ListNode p1 = head;
        //第一个结点就是目标结点
        if (i < 1) {
            head = head.next;
            return head;
        }
        while (p1 != null) {
            if (index == i) {
                p1.next = p1.next.next;
                break;
            }
            p1 = p1.next;
            index++;
        }
        return head;

    }

    public int searchNode(ListNode listNode, int val) {
        int res = 1;
        while (listNode != null) {
            if (listNode.val == val) {
                //返回目标结点的前一个位置
                return res - 1;
            }
            listNode = listNode.next;
            res++;
        }
        return 0;
    }

}
```