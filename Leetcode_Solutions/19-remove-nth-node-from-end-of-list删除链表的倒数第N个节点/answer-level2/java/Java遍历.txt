### 解题思路
先遍历链表得到链表长度`count`，然后分为两种情况考虑：
1. `count==n`
2. `else`

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int count =0;

        ListNode count_p = head;
        while(count_p!=null){
            count++;
            count_p=count_p.next;
        }//count链表长度
        //System.out.println(count);

        if(n==count){
            head = head.next;
            //return head;
        }//删除头节点   
        else{
            ListNode delete_p = head;
            for(int i=0;i<count-n-1;i++){
                delete_p = delete_p.next;
            }

            ListNode next_p = delete_p.next.next;

            delete_p.next = next_p;

            //return head;
        }
        return head;
    }
}
```