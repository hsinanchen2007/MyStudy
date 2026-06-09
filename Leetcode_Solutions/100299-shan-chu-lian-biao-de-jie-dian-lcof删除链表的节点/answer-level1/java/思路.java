### 解题思路
此处撰写解题思路
我的思路:
    为了防止第一个就是要删除的数字，我判断了第一个节点是否要删除的，如果是我就用辅助几点直接
移动到原始头节点的下一个，然后再创建一个辅助的节点，是辅助移动头节点的，然后根据前一个进行next判断
如果下下一个地址找到是要删除的内容，那么就直接跳出循环，循环外进行判断是true还是false。进行当前的next
指向下一个的next的next最后返回那个辅助的节点,ok;
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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode temp=head;
        boolean flag=false;
        if(head.val==val){
            temp=head.next;
        }
        ListNode temp1=temp;
        while(temp.next!=null){
            if(temp.next.val==val){
                flag=true;
                break;
            }
            temp=temp.next;
        }
        if(flag){
            temp.next=temp.next.next;   
        }
        return temp1;
    }
}
```