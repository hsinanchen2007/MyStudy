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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode flag=new ListNode(0);
        int add=0;
        int index=0;
        int sum=(l1.val+l2.val);
        add=sum%10;
        flag.val=add;
        index=sum/10;
        if(l1.next==null&l2.next==null){
            if(index==1){
                flag.next=new ListNode(index);
            }
            else{
                flag.next=null;
            }

        }else if(l1.next==null&&l2.next!=null){
            flag.next=addTwoNumbers(new ListNode(index),l2.next);
        }else if(l1.next!=null&&l2.next==null){
            flag.next=addTwoNumbers(l1.next,new ListNode(index));
        }else{
            l1.next.val+=index;
            flag.next=addTwoNumbers(l1.next,l2.next);
        }


        return flag;

        

    }
}
```