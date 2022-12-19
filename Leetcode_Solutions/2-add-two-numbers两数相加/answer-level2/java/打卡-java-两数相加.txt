### 解题思路
依次遍历两个l1和l2，每次遍历一个节点就进行一次两个个位数相加的运算。

**注意：**  
- 由于返回链表也为倒叙记录的，因此采取两个变量head和result。head来记录链表头节点，用来返回结果。result用来记录链表最后一个有记录的元素，用来完成链表尾插。
- 思路比较简单就是需要考虑的情况比较多。

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
//如果其中一个是0就返回另一个

        if (l1.val==0&&l1.next==null){
            return l2;
        }
        if (l2.val==0&&l2.next==null){
            return l1;
        }
        int jin=0;
        int sum=0;
        ListNode result=null;
        ListNode head=null;
        while(l1!=null && l2!=null){
            sum=l1.val+l2.val+jin;
            jin=sum/10;
            sum=sum%10;
            ListNode temp=new ListNode(sum);
            //第一个节点,并记录首节点
            if (result == null){
                temp.next=result;
                result=temp;
                head=result;
            }else{
                //result不为null,进行尾部插
                temp.next=result.next;
                result.next=temp;
                result=result.next;
            }
            l1=l1.next;
            l2=l2.next;
        }
        if(l1==null&&l2==null){
            if (jin!=0){
                ListNode temp=new ListNode(jin);
                temp.next=result.next;
                result.next=temp;
            }
            return head;
        }
        if (l1==null&&l2!=null){
            while(jin!=0&&l2!=null){
                sum=l2.val+jin;
                jin=sum/10;
                sum=sum%10;
                ListNode temp=new ListNode(sum);
                temp.next=result.next;
                result.next=temp;
                result=result.next;
                l2=l2.next;
            }
            if (jin==0&&l2!=null){
                result.next=l2;
            }
            if (jin!=0 && l2==null){
                ListNode temp=new ListNode(jin);
                temp.next=result.next;
                result.next=temp;
            }
        }
        if (l2==null&&l1!=null){
            while(jin!=0&&l1!=null){
                sum=l1.val+jin;
                jin=sum/10;
                sum=sum%10;
                ListNode temp=new ListNode(sum);
                temp.next=result.next;
                result.next=temp;
                result=result.next;
                l1=l1.next;
            }
            if (jin==0&&l1!=null){
                result.next=l1;
            }
            if (jin!=0 && l1==null){
                ListNode temp=new ListNode(jin);
                temp.next=result.next;
                result.next=temp;
            }
        }
        return head;
    }
}
```