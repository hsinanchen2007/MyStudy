### 解题思路
要多思考循环的截止条件到底是当前为空还是下一个为空

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode temp1= new ListNode(0);
        ListNode temp2 = temp1;
        while(l1!=null && l2!=null){
            if(l1.val<l2.val){
                temp1.next = l1;
                temp1 = temp1.next;
                l1 = l1.next;
            }else{
                temp1.next = l2;
                temp1 = temp1.next;
                l2 = l2.next;
            }
        }
        temp1.next = l1==null?l2:l1;
        return temp2.next;

    }
}
```