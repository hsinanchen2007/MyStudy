### 解题思路
此处撰写解题思路
首先遍历链表求出长度len，
根据len和n得出要删除的下标index,
当链表移动到下标index的时候进行删除，
需要注意的情况只有当len等于n的情况，这种情况下直接更改链头就好
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
       if(head==null){
            return null;
        }
        ListNode ans = head;
        ListNode temp = head;
        int len = 1;
        while (head.next!=null){
            len++;
            head = head.next;
        }
        if(len==1&&n==1){
            return null;
        }
        int index = len - n;
        head = ans;
        if(index==0){
            ans = head.next;
            return ans;
        }
        do{
            if(index==0){
                head = temp;
                head.next = head.next.next;
            }
            temp = head;
            head = head.next;
            index--;
        }while (index!=-1);
        return ans;
    }
}
```