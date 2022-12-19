### 解题思路
此处撰写解题思路
我的思路:
    首先必须判断一下这个两链表当前的值是否为空的，如果为空就返回null!其中一方不为空就返回不为空的一方！

    准备工作:
        用两个辅助的指针变量s1,s2,又创建了一个新的节点，又创建了两个保存指针地址的变量next1,next2;

    功能实现:
        首先死循环，判断s1和s2这两个辅助节点不为空
        然后再判断大小，将小的节点放入到新的链表中，我们放之前要将当前的节点的下一个next放入到next1中，因为要保留下一个的
地址，不然的话原先的链表就会断开的，我们将两个链表较小的值都放入到新的链表中之后
        再次判断这两个辅助的链表s1,s2是否长度不一样的，如果链表较短的已经执行完了以后，我们就直接用循环将长的链表全部放入到
新的链表当中，直接跳出循环，如果不跳出循环的话，那么它还会继续执行的！
        最后我们将新的链表进行排序算法的比较排序，通过前一个链表的节点和后一个节点进行计较，一直进行交换；
        直接返回已经交换的的链表的值返回即可;
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
        if(l1!=null && l2==null){
            return l1;
        }else if(l1==null && l2!=null){
            return l2;
        }else if(l1==null && l2==null){
            return null;
        }
        ListNode s1=l1;
        ListNode s2=l2;
        ListNode s3=new ListNode(0);
        ListNode next1=null;
        ListNode next2=null;
        while(true){
            if(s1==null && s2==null){
                break;
            }

            if(s1.val==s2.val){
                next1=s1.next;
                next2=s2.next;
                s1.next=s3.next;
                s3.next=s1;
               
                s2.next=s3.next;
                s3.next=s2;
                s1=next1;
                s2=next2;
                       
            }else if(s1.val < s2.val){
                next1=s1.next;
                s1.next=s3.next;
                s3.next=s1;
                s1=next1;
            }else if(s2.val < s1.val){
                next2=s2.next;
                s2.next=s3.next;
                s3.next=s2;
                s2=next2;
            }

            if(s1!=null && s2==null){

                while(s1!=null){
                       next1=s1.next;
                      s1.next=s3.next;
                          s3.next=s1;
                       s1=next1;
                }
                break;
            }else if(s1==null && s2!=null){
                while(s2!=null){
                next2=s2.next;
                            s2.next=s3.next;
                            s3.next=s2;
                            s2=next2;
                }
            break;
            }
        }
      ListNode temp=s3.next;
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


        return s3.next;
    }
}
```