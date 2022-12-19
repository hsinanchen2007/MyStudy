### 解题思路
1.因为返回链表，首先构建第三方链表，用0初始化。
2.两个链表数相加时，取值取到null，设置为0
3.相加后 /10 取十位，%10 取个位；而十位用于下一次取值相加，个位用于补充第三方链表
4.当两个链表不取到null时候，继续取下一个值
5.返回第三方链表除第一个值外


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

        ListNode root = new ListNode(0);
        ListNode cursor = root;
        int carry = 0;
        while(l1 != null || l2 != null || carry !=0){
            int l1val = l1 != null ?l1.val:0;
            int l2val = l2 != null ?l2.val:0;
            int sumVal = l1val + l2val + carry;
            carry = sumVal /10;

            ListNode sumNode = new ListNode(sumVal % 10);
            cursor.next = sumNode;
            cursor = sumNode;

            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }
        return root.next;
    }
}
```