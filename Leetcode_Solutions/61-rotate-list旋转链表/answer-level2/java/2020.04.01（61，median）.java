### 解题思路
本题思路和`19`题有相似之处

- 首先对链表**判空**，确立算法出口

- 然后排除**移动位置恰好等于链表长度倍数**的情况，则直接返回链表头结点即可

- 特殊情况排除后，要先找到**链表尾结点**`tail`，固定好**链表的头结点**`start`，经过移动后`tail`要指向`start`

- 然后再创建两个移动指针用来**寻找断链位置**，并将指针指向**断链两端**

- 创建指针`newHead`指向后一半的头结点也是**新链的头结点**，再将**尾结点指向旧的头结点**`start`，则新链就连好了

- 最后返回新链的头结点`newHead`即可。

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
    public ListNode rotateRight(ListNode head, int k) {
        // 对 head 结点判空
        if (head == null) {
            return head;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        // 固定 start 结点指向链表头部
        ListNode start = head;
        // 计算链表长度
        int len = 0;
        ListNode cur = head;
        while (cur != null) {
            len++;
            cur = cur.next;
        }
        // 如果移动次数是链表的倍数则代表不需要移动
        if (k % len == 0) {
            return head;
        }
        // 标记尾指针
        ListNode tail = head;
        while (tail != null && tail.next != null) {
            tail = tail.next;
        }
        // 创建移动指针寻找断链位置
        ListNode first = dummy;
        ListNode end = dummy;
        // 确定移动距离
        int cnt = 0;
        while (end != null && cnt < k % len + 1) {
            end = end.next;
            cnt++;
        }
        while (end != null) {
            first = first.next;
            end = end.next;
        }
        // 创建新的头结点链接改变后的元素
        ListNode newHead = first.next;
        first.next = null;
        tail.next = start;
        // 返回新的头结点
        return newHead;
    }   
}
```