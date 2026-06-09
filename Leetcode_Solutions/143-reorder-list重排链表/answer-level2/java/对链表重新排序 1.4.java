### 解题思路
Step1：找到链表的中间结点。（关键是要对链表进行分割）
Step2：对链表的后半子链表进行逆序。
Step3：把前半部分后逆序后的后半部分合并。（合并算法注意下。）
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
        if(head==null||head.next==null){
            return;
        }
        //step1：找到中间节点并将链表一分为二
        ListNode middleNode = FindMiddleListNode(head);
        ListNode left = head;
        ListNode right = middleNode.next;
        middleNode.next = null;
        //step2：对后面的链表进行逆序
        right = Reverse(right);
        //step3：合并两个链表
        ListNode leftTemp;
        ListNode rightTemp;
        while(left!=null&&right!=null){
            //1. 保存next节点
            leftTemp = left.next;
            rightTemp = right.next;
            //2. 将右链表的第一个节点插入到左链表中
            // 左链表：1->2->3 右链表：5->4 
            // 合并后的左链表：1->5->2->3 
            left.next = right;
            right.next = leftTemp;
            //3. 移动left和right指针
            //左链表变为：2->3 右链表变为：4
            left = leftTemp;
            right = rightTemp;
        }
    }

    //快慢指针找到中间节点
    public ListNode FindMiddleListNode(ListNode head){
        if(head==null||head.next==null)
            return head;
        ListNode fast = head;
        ListNode slow = head;
        while(fast!=null&&fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    //翻转链表
    public ListNode Reverse(ListNode head){
        if(head==null||head.next==null)
            return head;
        ListNode newHead = Reverse(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }
}

```