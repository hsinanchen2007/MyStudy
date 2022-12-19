### 解题思路

使用归并的方法

1、找到中间节点
2、把链表分成两部分
3、合并两个链表，使用两个指针比较


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
    public ListNode sortList(ListNode head) {
        
        if(head==null||head.next==null){
            return head;
        }

        ListNode midNode = getMiddle(head);

        ListNode right = midNode.next;
        midNode.next = null;
        ListNode left = head;

        return merge(sortList(left),sortList(right));
    }

    //合并
    public ListNode merge(ListNode left,ListNode right){
        
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        while(left!=null && right!=null){
            if(left.val <= right.val){
                curr.next = left;
                left = left.next;
            }else{
                curr.next = right;
                right = right.next;
            }
            curr = curr.next;
        }

        if(left==null){
            curr.next = right;
        }else{
            curr.next = left;
        }

    return dummy.next;
}

    //找到中间节点
    public ListNode getMiddle(ListNode head){
        ListNode fast = head;
        ListNode slow = head;

        while(fast.next!=null && fast.next.next!=null){
            fast = fast.next.next;
            slow = slow.next;
        }

        if(fast.next==null){
            return slow;
        }else{
            return slow;
        }
    }
}
```