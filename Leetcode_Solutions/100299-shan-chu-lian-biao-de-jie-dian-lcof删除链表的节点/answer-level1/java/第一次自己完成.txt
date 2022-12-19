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
    /**
    *我把整个过程分成两部分，一是要删除的点在头结点，二是其他位置。
    1、在头结点仅需要把返回链表的头结点换成该头结点的下一位即可，且满足了该节点已删除。
    2、其他位置，调用我写的函数，输入现在的节点和要找的值，不管找没找到，头结点都不会变，因为删除的点在其他位置。
    （1）如果该节点的值等于要找的值那就是该节点，返回该节点
    （2）如果该节点已经是空了，说明找完了，返回空（3）如果在该节点处不相等，接着调用该函数递归的往下找，判断返回的节点，
    如果返回的不是空，说明在下一次找到了，就把当前的节点的next赋值给返回的节点的next，这一步是为了删除确定的节点，
    然后返回空。
    */
    public ListNode deleteNode(ListNode head, int val) {
        if(head.val==val){  
            return head.next;//一是要删除的点在头结点,
//在头结点仅需要把返回链表的头结点换成该头结点的下一位即可，且满足了该节点已删除。
        }
        else{
            que(head,val);//二是其他位置。调用我写的函数，输入现在的节点和要找的值，
            return head;//不管找没找到，头结点都不会变，因为删除的点在其他位置。
        }
    }
    public ListNode que(ListNode head,int val){
        if(head==null) return null;
        if(val==head.val) return head;
        else {
            ListNode l =  que(head.next,val);
            if(l!=null) head.next = l.next;
            return null;
            
        }
    } 
 }

```