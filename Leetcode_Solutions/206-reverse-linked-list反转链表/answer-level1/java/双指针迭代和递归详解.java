### 双指针迭代

双指针迭代的解法基本就是定义两个辅助的指针，不停的变换两个指针的指向，使单链表进行反转。
比如输入：1->2->3->4->5时，第1个结点时，prev = null，curr=head;定义1个临时变量存储curr的下一个结点，再执行curr.next = prev
,将1的下一个结点指向prev(null),此时，单链表为：null<-1 2->3->4->5;再执行prev = curr后，将prev指向1,再执行curr = temp，
将curr指向结点2；依次类推：当head=2时，执行完后，单链表为：null<-1<-2 3->4->5,直到head=5时，执行完为：null<-1<-2<-3<-4<-5；
退出while，返回prev，即结点5。
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 * 
 * 双指针迭代
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        //定义两个辅助指针
        ListNode prev = null;
        ListNode curr = head;
        while (null != curr) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
}
```


### 递归

1. 首先考虑边界值，当head=null时，返回null；当head.next=null时，返回head(当前结点)，表示递归结束；
2. 开始递归
比如输入：1,2,3,4,5 时，当head = 5时递归结束，返回head；
即在第4次递归时，curr = 5,继续向下执行，head.next.next=head=4,即指明结点4的下一个结点(5)指向结点4；注意：此时链表为：               1->2->3->4->5->4，此时链表具有一个环形结构:4->5->4；然后执行下一步head.next = null,即将链表中4->5->4的环状结构破坏,即变为1->2->3->4 5->4，再返回curr，即第1个结点；
依次类推;当head=1的这次递归执行完后,链表已经变为:5->4->3->2->1
注意：每次递归完后都会返回1个curr，这是表示链表的第1个结点，这个值在第4次递归完成后就不会改变，知道递归结束。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 * 
 * 递归解法
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if (null == head || null == head.next) {
            return head;
        }

        //递归调用
        ListNode curr = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return curr;
    }
}
```