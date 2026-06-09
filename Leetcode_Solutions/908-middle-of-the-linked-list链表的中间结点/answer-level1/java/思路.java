### 解题思路
此处撰写解题思路
我的思路：
    首先我们循环得到这个链表的中的节点的长度
然后再用for循环到中间，（用链表的长度除以2就可以了）;
最后返回的就是这个链表
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
        ListNode temp=head;
        ListNode cur=head;
        int len=0;
        while(temp!=null){
            len++;
            temp=temp.next;
        }
            for(int i=0;i<len/2;i++){
                cur=cur.next;
            }

        return cur;
    }
}
```