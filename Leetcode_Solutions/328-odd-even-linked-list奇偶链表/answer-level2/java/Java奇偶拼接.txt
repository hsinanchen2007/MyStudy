count记录奇偶下表，奇数偶数各一个节点一起遍历，最后拼接。
需要注意的是后半部分需要在便利结束后让指针归null


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
    public ListNode oddEvenList(ListNode head) {
        int cnt = 1;
        ListNode oddDummy = new ListNode(0);
        ListNode evenDummy = new ListNode(0);
        ListNode odd =  oddDummy;
        ListNode even = evenDummy;
        while(head!=null){
            if(cnt%2!=0){
                odd.next = head;
                odd = odd.next;
            }else{
                even.next = head;
                even = even.next;
            }
            head = head.next;
            cnt++;
        }
        odd.next = evenDummy.next;
        even.next = null;
        return oddDummy.next;
    }
}
```