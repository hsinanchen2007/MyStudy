### 解题思路
模拟进位

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head=new ListNode((l1.val+l2.val)%10);
        ListNode point=new ListNode(0);
        point=head;
        int add=l1.val+l2.val>=10?1:0;
        while(true){
            l1=l1.next;
            l2=l2.next;
            if(l1==null && l2==null){//只剩下进位
                if(add==1){
                    point.next=new ListNode(1);
                }
                break;
            }
            ListNode temp=new ListNode(1);
            if(l1==null){//l2比l1长
                l1=new ListNode(0);
                temp.val=(l2.val+add)%10;
                add=l2.val+add>=10?1:0;
            }
            else if(l2==null){//l1比l2长
                l2=new ListNode(0);
                temp.val=(l1.val+add)%10;
                add=l1.val+add>=10?1:0;
            }
            else{
                temp.val=(l1.val+l2.val+add)%10;
                add=l1.val+l2.val+add>=10?1:0;
            }
            
            point.next=temp;
            point=point.next;
        }
        return head;
    }
}
```