/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/29
 *
 * 解题思路: 快慢指针找到中点 慢指针反转前一半节点 然后背向移动进行值比较 （注意: 加一个奇偶数判定）
 *
 */
```
//示例 链表反转
    public void reverse(ListNode head){
        ListNode pre = null;
        ListNode p = head;

        while(head != null){
            head = head.next;
            p.next = pre;
            pre = head;
        }
    }

    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null){
            return true;
        }

        //找到中点 并反转链表
        ListNode slow = head;
        ListNode pre = null;
        ListNode fast = head;

        boolean isJS = true;

        while(fast.next != null){

            if(fast.next != null)
                fast = fast.next;
            if(fast.next != null){
                fast = fast.next;
            }else{
                isJS = false;
            }

            //慢指针前进并反转
            slow = slow.next;
            head.next = pre;
            pre = head;
            head = slow;
        }


        ListNode left = pre;
        ListNode right = slow;
        if(isJS){
            right = slow.next;
        }

        while(left != null && right != null){
            if(left.val != right.val){
                return false;
            }
            left = left.next;
            right = right.next;
        }

        return true;

    }
```