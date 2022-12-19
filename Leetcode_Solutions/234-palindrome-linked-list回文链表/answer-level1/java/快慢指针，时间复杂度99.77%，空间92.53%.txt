我一直觉得自己是链表操作的小菜鸟。面对本题完全没思路，看了大神的启发，快慢指针，好吧有了思路就开始自己施工了。实现完全自己写的，链表操作如果不熟练强烈建议用笔画画。
献上自己的草稿，比较丑，不知道能不能看懂


![屏幕快照 2019-11-06 下午3.32.28.png](https://pic.leetcode-cn.com/b3679a3891760a1addf37966e029e8a948eb263dce92176367d6bb007c06ef9b-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-06%20%E4%B8%8B%E5%8D%883.32.28.png)
![屏幕快照 2019-11-06 下午3.32.42.png](https://pic.leetcode-cn.com/b4d427b639cb61bd70bfad00fe970ffd65ffe91cd3122551386f8a9688cff662-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-06%20%E4%B8%8B%E5%8D%883.32.42.png)
```
    public  boolean isPalindrome(ListNode head) {
        ListNode old = null, slow = head, fast = head, temp = null;

        while (fast != null && fast.next != null) {
            //移动快指针
            fast = fast.next.next;
            //慢指针移动的同时进行颠倒
            temp = slow.next;
            slow.next = old;
            old = slow;
            slow = temp;

        }
        //判定奇偶，偶数fast为空，奇数fast不为空。以1-8为例，fast为空，1-9为例，fast=9
        if (fast != null) {
            slow = slow.next;
        }
        while (old != null || slow != null) {
            if (old.val != slow.val)
                return false;
            old = old.next;
            slow = slow.next;
        }
        return true;
    }
```
