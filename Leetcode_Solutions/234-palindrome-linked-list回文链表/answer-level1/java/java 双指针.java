### 解题思路
先利用双指针原理遍历链表，便利的同时翻转链表，
因为快指针比慢指针每次多走一步，所以遍历完的时候慢指针刚好走在链表的中心，
同时也是翻转了一半链表，最后将翻转的与未翻转的作比较，得出结果，

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

    public boolean isPalindrome(ListNode head) {
        if(head==null || head.next == null)
			return true;
		// 翻转前半链表
		ListNode fast = head;	//快指针	head为慢指针
		ListNode prepre = null;	//保存翻转后的链表
		while(fast != null && fast.next != null) {
			//	快慢指针移动
			fast = fast.next.next;
			ListNode temp = head.next;
			
			head.next = prepre;
			prepre = head;
			head = temp;
		}
		//	防止链表是单数
		if(fast != null) {
			head = head.next;
		}
		// 将翻转的前半链表与未翻转的后半链表比较
		while(head != null) {
			if(head.val != prepre.val)
				return false;
			head = head.next;
			prepre = prepre.next;
		}
		return true;
    }
}
```