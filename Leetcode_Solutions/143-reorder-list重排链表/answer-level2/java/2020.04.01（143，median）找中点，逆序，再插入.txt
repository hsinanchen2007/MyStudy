### 解题思路
本题整体思路还是很清晰的，就是**将链表拆分成两部分**，**后一半逆序**后插入到前一半中即可

具体步骤如下:

- 首先对链表**判空**，给程序一个出口

- 若链表**不为空**，首先**计算链表长度**，定义`tmp`移动到链表中间位置，用一个指针`tail`保存链表后一半并断链
- （另解）上一步也可不用计算长度，直接用**快慢指针**`slow`和`fast`进行移动，`slow`一步一步走，`fast`一次走两步，遍历完后，`slow`刚好位于链表中间

- 找到中间位置后，将后一半链表**逆序**

- 逆序完的链表**交替插入**前半部分的链表**间隔**中即可

- 因题目中是`void`类型，所以最后**不用返回**链表结点了。

### 代码

```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {  
        if (head == null || head.next == null) {
            return;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        // 计算链表长度
        int len = 0;
        ListNode cur = head;
        while (cur != null) {
            len++;
            cur = cur.next;
        }
        
        // 划分链表
        ListNode tmp = dummy;
        // 这里 len + 1 是为了将奇数和偶数情况统一起来
        for (int i = 0; i < (len + 1) / 2; i++) {
            tmp = tmp.next;
        }
        ListNode tail = tmp.next;
        tmp.next = null;
        
        // 将后一半链表逆序
        tail = reverse(tail);
        
        // 将逆序链中的元素插入到 head 后面                
        while (tail != null) {
            ListNode p = tail.next;
            tail.next = head.next;            
            head.next = tail;
            head = tail.next;
            tail = p;           
        }
    }
    
    private ListNode reverse(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode end = head;
        head = head.next;
        end.next = null;

        while (head != null) {
            ListNode tmp = head.next;
            head.next = end;
            end = head;
            head = tmp;
        }
        return end;
    }
}
```