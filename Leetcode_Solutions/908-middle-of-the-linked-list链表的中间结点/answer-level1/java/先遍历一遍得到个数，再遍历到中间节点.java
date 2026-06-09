### 解题思路
此处撰写解题思路

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
    public ListNode middleNode(ListNode head) {
        if(head == null){
            return head;
        }
        ListNode p = head;
        int cnt = 0;
        int mid = 0;
        while(p.next != null){
            cnt++;
            p = p.next;
        }
        if(cnt % 2 == 0){
            mid = cnt / 2;
        }else{
            mid = cnt / 2 + 1;
        }
        p = head;
        int count = 0;
        while(p.next != null){
            count++;
            p = p.next;
            if(count == mid){
                break;
            } 
        }
        return p;
    }
}
```