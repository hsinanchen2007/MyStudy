![image.png](https://pic.leetcode-cn.com/f9b63c2d3ae690b5c0869d3f1d75519f24d723a2982adaa43dc5f81b7cf10a9e-image.png)
应该是最简洁的非递归代码了
```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head==null||head.next==null)return true;
        ListNode pre=null;
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            //slow边后移边反转前边
            ListNode next=slow.next;
            slow.next=pre;
            pre=slow;
            slow=next;
        }
        //奇数个的时候
        if(fast!=null){
            slow=slow.next;
        }

        while(slow!=null&&pre!=null&&slow.val==pre.val){
            slow=slow.next;
            pre=pre.next;
        }
        if(slow==null&&pre==null)return true;
        return false;
    }
}
```
