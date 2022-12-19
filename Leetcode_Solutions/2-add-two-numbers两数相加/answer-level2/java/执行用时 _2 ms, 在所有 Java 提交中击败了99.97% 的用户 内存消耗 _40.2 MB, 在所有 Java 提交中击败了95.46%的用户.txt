### 解题思路
储存一下位数，满10的后留一个数字，这题好坑啊，我错了好几遍。

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
        int temp=1,ad=0;
        ListNode old=new ListNode(temp);
        ListNode head=old;
        ListNode res;
        int end=0;
        while(true){
            ad=temp%10;
            temp=temp/10;
            res=new ListNode(ad);
            old.next=res;
            old=res;
            if(end==2&&temp==0)
                break;
            else
                end=0;
            temp+=l1.val;
            temp+=l2.val;
            if(l1.next!=null)
                l1=l1.next;
            else{
                l1.val=0;
                end++;
            }
                
            if(l2.next!=null)
                l2=l2.next;
            else{
                l2.val=0;
                end++;
            }
            
        }
         return head.next.next;
    }
}
```