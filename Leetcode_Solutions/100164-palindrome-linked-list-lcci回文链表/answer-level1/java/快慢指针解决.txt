# 解题思路：
1，采用快慢两个指针去寻找链表的中间节点；
2，根据链表的中间节点反转后一半的链表；
3，迭代比较链表前一半的元素和后一半的元素，判断节点的值是否相等，得出是否为回文。


# 图解：
![链表回文奇数.jpeg](https://pic.leetcode-cn.com/cb25ad29e4c902e12bfe088a79b491dc8e6ff890786f15ce6b176d5419bcbf71-%E9%93%BE%E8%A1%A8%E5%9B%9E%E6%96%87%E5%A5%87%E6%95%B0.jpeg)


![链表回文偶数.jpeg](https://pic.leetcode-cn.com/79a887a172f927142b591a28f2d4638223ee992279f6925ec418e1ce1cbc5c1a-%E9%93%BE%E8%A1%A8%E5%9B%9E%E6%96%87%E5%81%B6%E6%95%B0.jpeg)


# 解题代码：
```
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null) return true;

        ListNode midNode = findMidNode(head);
        ListNode secondHalfHead = reverseLinked(midNode.next);
        ListNode curr1 = head;
        ListNode curr2 = secondHalfHead;

        boolean palindrome = true;
        while(palindrome && curr2 != null){
            if(curr1.val != curr2.val) palindrome = false;
            curr1 = curr1.next;
            curr2 = curr2.next;
        }

        return palindrome;
    }

    /* 反转链表 */
    private ListNode reverseLinked(ListNode head){
        ListNode cur = head;
        ListNode prev = null;
        while(cur != null){
            ListNode nextTemp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nextTemp;
        }
        return prev;
    }

    /* 快慢指针寻找中间节点 */
    private ListNode findMidNode(ListNode head){
        ListNode fast = head;
        ListNode low = head;
        while(fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            low = low.next;
        }
        return low;
    }

}
```
