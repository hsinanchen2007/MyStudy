### 解题思路
巧妙的运用数据结构中的***二路归并***
将对应位相加
存下进位，将进位置于下一位处理

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
        int jw=0;//进位
        //先处理一位，产生头结点，便于后续操作
        ListNode l=new ListNode((l1.val+l2.val)%10);
        ListNode L=l;
        jw=(l1.val+l2.val)/10;
        l1=l1.next;
        l2=l2.next;
        //二路归并妙用
        while(l1!=null&&l2!=null){
            ListNode p=new ListNode((l1.val+l2.val+jw)%10);
            jw=(l1.val+l2.val+jw)/10;
            l.next=p;
            l=p;
            l1=l1.next;
            l2=l2.next;
        }
        //l1有残余项
        while(l1!=null){
            ListNode p=new ListNode((l1.val+jw)%10);
            jw=(l1.val+jw)/10;
            l.next=p;
            l=p;
            l1=l1.next;
        }
        //l2有残余项
        while(l2!=null){
            ListNode p=new ListNode((l2.val+jw)%10);
            jw=(l2.val+jw)/10;
            l.next=p;
            l=p;
            l2=l2.next;
        }
        //存在进位未处理
        if(jw!=0){
            ListNode p=new ListNode(jw);
            l.next=p;
        }
        return L;
    }
}
```