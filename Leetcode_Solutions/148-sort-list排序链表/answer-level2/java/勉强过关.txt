### 解题思路


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
        List<Integer> list=new ArrayList<>();
        ListNode x=head,y=head;
        int i=0;
        while(head!=null){
            list.add(head.val);
            head=head.next;
        }
        Collections.sort(list);
        while(x!=null){
            x.val=list.get(i++);
            x=x.next;
        }
        return y;
    }
}
```