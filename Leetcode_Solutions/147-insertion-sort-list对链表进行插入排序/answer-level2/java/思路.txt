### 解题思路
此处撰写解题思路
我的思路:
    首先判断链表的内容是否为空！
    然后再用前面一个和后面一个进行比较，如果前面的大于后面的一个，那么就将后面的一个放入到前面来，前面的一个放到
后面去，最后返回head,ok;
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
    public ListNode insertionSortList(ListNode head) {
        ListNode temp=head;
    if(head==null)return null;
        while(temp.next!=null){
            ListNode cur=temp.next;
            while(cur!=null){
                if(temp.val>cur.val){
                    int k=temp.val;
                    temp.val=cur.val;
                    cur.val=k;
                }
                cur=cur.next;
            }
            temp=temp.next;
        }
        return head;
    }
}
```