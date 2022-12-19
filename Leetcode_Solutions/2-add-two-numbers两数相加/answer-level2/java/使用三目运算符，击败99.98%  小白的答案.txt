### 解题思路
此处撰写解题思路
具体思路见代码
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
// class Solution {
//     public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
// ////分为三种情形
// //首节点用 dummyhead    
//     if(l1 == null) return l2;
//     if(l1 == null) return l2;
//     ListNode dummy = new ListNode(0);//哑节点,方便处理 若开头为0 符合数字的规律
//     ListNode cur = dummy;//复制一个cur节点，避免破坏头结点
//     int carry = 0;
//     while(l1 != null && l2 != null){
//         int sum = l1.val +l2.val + carry;
//         int val = sum % 10; //求余数
//         //int carry = sum/10; 注意这里 变量已经被定义了，就无需再次定义
//         carry = sum/10;
//         ListNode newnode = new ListNode(val);
//         cur.next = newnode;
//         cur = cur.next;
//         l1 = l1.next;
//         l2 = l2.next;
//     }
//     while(l1 != null){//当 l2太短了
//         int val = (l1.val + carry)%10;
//         carry = (l1.val + carry)/10;
//         ListNode newnode = new ListNode (val);
//         cur.next = newnode;
//         cur = cur.next;
//         l1 = l1.next;
//     }
//      while(l2 != null){//当 l2太短了
//         int val = (l2.val + carry)%10;
//         carry = (l2.val + carry)/10;
//         cur.next = new ListNode(val);
//         cur = cur.next;
//         l2 = l2.next;
//     }
//     if(carry != 0){
//         cur.next = new ListNode(carry); 
//     }
//     return dummy.next;
//     }
// }
public class Solution{
    public ListNode addTwoNumbers(ListNode l1,ListNode l2){
        ListNode dummyhead = new ListNode(0);
        int carry = 0;
        ListNode cur = dummyhead;
        while(l1 != null || l2 != null || carry!= 0){
            int sum = ((l2 == null)? 0:l2.val) + ((l1 ==null)?0:l1.val) + carry;
            carry = sum/10;
            // val = sum %10;//这里要再次声明int 要么使用cur.val
            int val = sum %10;
            // ListNode cur.next = new ListNode(val);
            cur.next = new ListNode(val);//这里无需再次声明
            cur = cur.next;

            // l1 = (l1 == null)?0:l1.next;   //l1是节点 而非数字
            l1 = (l1 == null)?l1 : l1.next; 
            l2 = (l2 == null)?l2 : l2.next;//注意角标
        }
        return dummyhead.next;
    }

}





```