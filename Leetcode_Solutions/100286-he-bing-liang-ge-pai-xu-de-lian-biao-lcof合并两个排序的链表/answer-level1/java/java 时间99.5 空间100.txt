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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //拟定一个头节点，便于最后返回结果head.next
        ListNode head=new ListNode(0);
        ListNode tmp=head;
        while(l1!=null || l2!=null){
            if(l1==null){
                //如果l1为null了，那么将l2直接加入tmp的next节点即可（因为链表是有序的）
                tmp.next=l2;
                break;
            }else if(l2==null){
                //同上
                tmp.next=l1;
                break;
            }else{
                //如果均不为null，则比较l1和l2的值，小的那个变为tmp的next节点，并后移
                if(l1.val>l2.val){
                    tmp.next=l2;
                    l2=l2.next;
                }else{
                    tmp.next=l1;
                    l1=l1.next;
                }
                //tmp后移
                tmp=tmp.next;
            }
        }
        return head.next;
    }
}
```