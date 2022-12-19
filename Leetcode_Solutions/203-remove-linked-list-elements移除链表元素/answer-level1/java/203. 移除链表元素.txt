/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/28
 *
 * 解题思路: 脸部基本操作 不多说
 */
```
public ListNode removeElements(ListNode head, int val) {
        ListNode pre_head = new ListNode(0);
        pre_head.next = head;

        ListNode p = head;
        ListNode pre = pre_head;

        while(p != null){
            if(p.val == val){
                pre.next = p.next;
            }else{
                pre = pre.next;
            }
            p = p.next;
        }

        return pre_head.next;
    }
```