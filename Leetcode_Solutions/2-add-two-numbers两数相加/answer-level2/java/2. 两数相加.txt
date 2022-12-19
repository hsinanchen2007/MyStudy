/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/13
 * 
 * 解题思路: 模拟法 直接相加即可
 * 
 */
```
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode head = new ListNode(0);
    ListNode p = head;
    //进位
    int JW = 0;
    //第一个数
    int d1 = 0;
    //第二个数
    int d2 = 0;
    while(l1 != null || l2 != null || JW != 0){
        d1 = 0;
        d2 = 0;
        if(l1 != null){
            d1 = l1.val;
            l1 = l1.next;
        }

        if(l2 != null){
            d2 = l2.val;
            l2 = l2.next;
        }

        ListNode in = new ListNode((d1 + d2 + JW)%10);
        JW = (d1 + d2 + JW)/10;
        p.next = in;
        p = p.next;
    }
    return head.next;
}
```