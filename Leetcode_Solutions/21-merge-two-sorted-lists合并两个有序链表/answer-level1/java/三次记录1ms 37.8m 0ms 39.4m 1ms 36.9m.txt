### 解题思路
设置p指针在l1和l2之间指来指去，同时l1和l2后移，知道两者中的一个为null衔接另一个链表剩余的部分结束

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
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null||l2==null){
            if(l1!=null)return l1;
            else if(l2!=null)return l2;
            else return null;
        }
        ListNode result;
        if(l1.val<l2.val){
            result=l1;l1=l1.next;
        }else {
            result=l2;l2=l2.next;
        }
        ListNode p=result;

        while (true){
            if(l1==null){
                p.next=l2;
                break;
            }
            if(l2==null){
                p.next=l1;
                break;
            }
            if(l1.val<l2.val){
                p.next=l1;l1=l1.next;
            }else{
                p.next=l2;l2=l2.next;
            }
            p=p.next;

        }return result;
    }
}


```