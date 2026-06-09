思路：1.首先判断首节点的大小，将小的节点作为头结点
           2. 判断此时节点的大小，如果l1的节点小于等于l2, 则需要在l1节点里循环遍历直至找到当前节点的下一个节点大于l2当前的节点，l1首先记录此时节点的下个节点temp, 并将当前节点指向l2, l1移动到temp的位置，如果l2的节点小于此时的l1的节点，同理可得。
    3.最后直接返回head头结点
     由于未创建新的头结点，是在原先链表的基础上合并的， 不需要考虑最后链表哪一个为空的情况，即非null的链表也不会丢失
```
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
        if(l1==null && l2!=null){
            return l2;
        }
        if(l1!=null && l2==null){
             return l1;
        }
        if(l1==null && l2==null){
            return null;
        }
        ListNode new_head=null;
        if(l1.val<=l2.val){
            new_head=l1;
        }else{
            new_head=l2;
        }
        while(l1!=null && l2!=null){
            if(l1.val<=l2.val){
                //循环找，直到下一个值大于它
                while(l1.next!=null ){
                    if(l1.next.val>l2.val){
                        break;
                    }
                    l1=l1.next;
                }
                ListNode temp=l1.next;
                l1.next=l2;
                l1=temp;
            }else{
                 while(l2.next!=null){
                    if(l2.next.val>l1.val){
                        break;
                    }
                    l2=l2.next;
                }
                ListNode temp=l2.next;
                l2.next=l1;
                l2=temp;
            }
        }

        return new_head;
    }
}
```
