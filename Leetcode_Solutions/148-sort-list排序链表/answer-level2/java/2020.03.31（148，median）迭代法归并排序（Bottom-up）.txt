### 解题思路
本题要求在 `O(n log n)` 时间复杂度和常数级空间复杂度下排序
- 意味着**不能用递归**方法求解，那么只有迭代法
- 还有`O(n log n)`的时间复杂度表示只能**用归并排序**（`Merge Sort`）

接下来梳理一下**算法思路**：

- 首先要先确立链表的长度，然后通过`for`循环对链表元素进行**倍速遍历**（每次将上一步的两部分合为一部分）

- 定义`first`和`second`指针指向每一部分的头结点，每次**事先保存每一部分的后继结点**再将其断链送入`Merge`进行排序

- 将排序好的链表用`pre`指针连接起来，再将剩下的`remain`部分链表挂到尾部进入下一轮**翻倍循环**

- 等到最后一轮`for`循环结束，如有剩余元素就挂在已排序链表尾部，如果恰好等分排好整条链表，就返回`dummy.next`即可。

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
    public ListNode sortList(ListNode head) {
        // 确定链表长度
        int len = 0;
        ListNode cur = head;
        while (cur != null) {
            len++;
            cur = cur.next;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        // 每次结合的元素翻倍实现由零到整的过程
        for (int m = 1; m < len; m *= 2) {
            ListNode pre = dummy;
            cur = pre.next;
            // 每次取出两部分归并排序后合并成一个部分
            while (cur != null) {
                // 定义 first 指针指向第一部分
                ListNode first = cur;
                for (int i = 0; i < m - 1 && cur != null; i++) {
                    cur = cur.next;
                }
                if (cur == null) {
                    break;
                }
                // 定义 second 指针指向第二部分
                ListNode second = cur.next;
                // 将第一部分和第二部分断开
                cur.next = null;
                cur = second;
                for (int i = 0; i < m - 1 && cur != null; i++) {
                    cur = cur.next;
                }
                ListNode remain = null;
                // 将第二部分与第三部分断开
                if (cur != null) {
                    remain = cur.next;
                    cur.next = null;
                }
                cur = remain;
                // 准备开始归并排序,并用 tmp 指向归并后的头结点
                ListNode tmp = merge(first, second);
                pre.next = tmp;
                // pre 结点遍历到归并链表的末尾
                while (pre.next != null) {
                    pre = pre.next;
                }
                // 接上剩下未排序的元素
                pre.next = remain;
            }
        }
        return dummy.next;
    }
    
    private ListNode merge(ListNode a, ListNode b) {
        ListNode pre = new ListNode(0);
        ListNode cur = pre;
        while (a != null && b != null ) {
            if (a.val < b.val) {
                cur.next = a;
                cur = cur.next;
                a = a.next;
            } else {
                cur.next = b;
                cur = cur.next;
                b = b.next;
            }
        }
        if (a != null) {
            cur.next = a;
        }
        if (b != null) {
            cur.next = b;
        }
        return pre.next;
    }
}
```