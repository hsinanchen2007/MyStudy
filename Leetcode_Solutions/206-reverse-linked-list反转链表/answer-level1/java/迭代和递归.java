### 解题思路
迭代的时候，如果后面的一个变量可由当前的变量，创建出来，不需要新建一个变量表示

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
    public ListNode reverseList(ListNode head) {
        //递归终止条件是当前为空，或者下一个节点为空
		if(head==null || head.next==null) {
			return head;
		}

		//这里的cur就是最后一个节点
		ListNode cur = reverseList(head.next);
		
        //这里请配合动画演示理解
		//如果链表是 1->2->3->4->5，那么此时的cur就是5
		//而head是4，head的下一个是5，下下一个是空
		//所以head.next.next 就是5->4
		head.next.next = head;
		
        //防止链表循环，需要将head.next设置为空
		head.next = null;
		
        //每层递归函数都返回cur，也就是最后一个节点
		return cur;
        
        /*
        //当前正在执行的链表
        ListNode curr   = head;

        //前一个链表
        ListNode pref   = null;

        //后一个链表
        ListNode next   = head.next;

        //循环反转链表 curr的后一个指针可以被curr创建起来 因此 没必要专门新建一个变量保存后序节点
        while (next != null) {
            curr.next = pref;
            pref      = curr;
            curr      = next;
            next      = next.next;
        }

        //循环到尾部 - 4
        curr.next = pref;

        return curr;
        */
    }
}
```