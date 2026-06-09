### 解题思路
可能是用了栈，性能极差

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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dumpy=new ListNode(0);
        Stack<ListNode> sk=new Stack<ListNode>();
        ListNode cur=dumpy;
        
        int length=0;
        ListNode lcur=head;
        while(lcur!=null){
            length++;
            lcur=lcur.next;
        }
        if(k==1||k>length)return head;
        int j=0;
        while((j+k-1)<length){
        for(int i=0;i<k;i++){
            sk.push(head);
            head=head.next;
        }
        
        while(sk.size()!=0){
            ListNode temp=sk.pop();
            cur.next=temp;
            cur=cur.next;
        }
            cur.next=head;
            j+=k;}
        return dumpy.next;
        
    }
}
```