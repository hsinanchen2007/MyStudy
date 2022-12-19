![image.png](https://pic.leetcode-cn.com/1096abb085ef946564be14fd2cd65e2d92e8c8aedd022c4f668265f775aafa86-image.png)


1.找到链表中间点mid.快指针前进两次，mid前进一次；
2.反转mid之后链表；
3.逐次比较
改进：可以在mid中边遍历边改变前半截链表指向，效率更高，不用额外reverse;

class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;
        ListNode mid = head, fast = head;
        while(fast.next != null){
            fast = fast.next;
            if(fast.next != null){
                fast = fast.next;
                mid = mid.next;
            }       
        }
        ListNode right = mid.next;
        mid.next = null;
        right = reverse(right);
        mid.next = null;
        while(right.val == head.val){
            if(right.next == null) return true;
            right = right.next;
            head = head.next;
        }
        return false;
    }
    private ListNode reverse(ListNode head){
        ListNode pre = null;
        ListNode next = head;
        while(next!=null){
            ListNode temp = next.next;
            next.next = pre;
            pre = next;
            next = temp;
        }
        return pre;
    }
}