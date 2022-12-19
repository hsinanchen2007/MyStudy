### 解题思路
两个指针，一个用于先探明链表长度，再根据给定的位置，用第二个指针移动到给定位置的前一个。
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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode temp=head;
        ListNode result=head;
        if(head==null||head.next==null)return head;
        //指针移到链表最后
        int sum=0;
        while(temp.next!=null){
            sum++;
            temp=temp.next;
        }
        if(sum<k)return result;
        int index=1;
        while(index<=(sum-k)){
            result=result.next;
            index++;
        }
        return result.next;
    }
}
```