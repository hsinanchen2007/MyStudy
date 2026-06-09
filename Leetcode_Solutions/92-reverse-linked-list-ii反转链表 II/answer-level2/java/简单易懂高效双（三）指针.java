### 解题思路
使用双指针思想：
（1）创建一个哑节点（可能存在头节点需要调换）
（2）从头节点开始，寻找开始调换的位置m，并保存前一节点信息
（3）使用双指针，将后一节点的下一节点变为前一个节点
（4）调换结束，将调换的段j重新接入链表

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == n) return head;
        ListNode newHead = new ListNode(0);
        int now = 1;
        ListNode first = newHead;
        //用于记录开始调换的节点的前一节点
        ListNode begin = null;
        //用于记录开始调换的节点
        ListNode beginNext = null;
        newHead.next = head;
        ListNode second = head;
        ListNode third = null;
        //寻找开始节点
        while (second.next !=null){
            if (m == now) break;
            first = first.next;
            second = second.next;
            now++;
        }
        begin = first;
        beginNext = second;
        third = second.next;
        //开始调换
        while (third != null && now != n){
            second.next = first;
            first = second;
            second = third;
            third = third.next;
            now++;
        }
        second.next = first;
        begin.next = second;
        beginNext.next = third;
        return newHead.next;




    }
}
```