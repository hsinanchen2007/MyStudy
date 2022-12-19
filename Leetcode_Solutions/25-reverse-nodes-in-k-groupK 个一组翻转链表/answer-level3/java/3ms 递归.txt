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
    public ListNode reverseKGroup(ListNode head, int k) {
        List<ListNode> list=new ArrayList<>();
        ListNode temp=head;
        ListNode headone;
        int len=0;
        while(temp!=null){
            len++;
            temp=temp.next;
        }
        if(len<k){
            return head;
            
        }else{
            ListNode temp1=head;
            for(int i=0;i<k;i++){
                list.add(temp1);
                temp1=temp1.next;
            }
            head=temp1;
            headone=list.get(k-1);
            for(int i=k-2;i>=0;i--){
                headone.next=list.get(i);
                headone=headone.next;
            }
            headone.next=reverseKGroup(head, k);
            
        }
        return list.get(k-1);
    }
}
- 无序列表