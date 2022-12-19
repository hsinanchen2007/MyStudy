### 解题思路
一开始的错误思路是把链表里的数转换成数字，然后两个数字相加，结果再转换为链表，结果掉进了坑里，有的测试点的数设置的很大，int装不下，还是得这样

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
    public int carry=0;
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l3=new ListNode(0),head=l3;
        while(l1!=null && l2!=null){
            int sum = l1.val+l2.val +carry;
            if(sum>=10)carry=1;else carry=0;
            ListNode p=new ListNode(sum%10);
            l3.next=p;
            l3=p;
            l1=l1.next;
            l2=l2.next;
        }
        if(l1!=null || l2!=null){
            l1=(l1!=null) ? l1 : l2;
            while(l1!=null){
                int sum=l1.val + carry;
                if(sum>=10)carry=1;else carry=0;
                ListNode p=new ListNode(sum%10);
                l3.next=p;
                l3=p;
                l1=l1.next;
                }
                if(carry==1)l3.next=new ListNode(1);
        }else if(carry==1){
            l3.next=new ListNode(1);
        }
        
    return head.next;
    }
}
```