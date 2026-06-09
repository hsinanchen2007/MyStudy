### 解题思路
本题两种思路

第一种思路：
- 按照常规思路**每次比较两条链的头结点元素**选出较小者接到新链的头结点后面
- 最后看哪条链还有剩余元素，然后直接接到新链末尾即可。

第二种思路：
- 利用**递归**求解，通过第一次比较选出作为链头的结点，之后递归的元素都会接在这个头结点之后
- 最后等到遍历完了所有元素，看哪条链还有剩余元素，此时返回没有剩余元素那条链的链头即可。

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        // 定义移动结点指针 p 升序链接合并后的元素
        ListNode p = dummy;
        ListNode p1 = l1;
        ListNode p2 = l2;
        // 两条链比较完后，用 p 依次链接较小元素
        while (p1 != null && p2 !=null) {
            if (p1.val <= p2.val) {
                p.next = p1;
                p = p.next;
                p1 = p1.next;
            } else {
                p.next = p2;
                p = p.next;
                p2 = p2.next;
            }
        }
        // 最后看哪个链有剩余元素，将其接在新链后面即可
        if (p1 != null) {
            p.next = p1;
        }
        if (p2 != null) {
            p.next = p2;
        }
        return dummy.next;
    }
}
```

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        // 第一次比较，选出最小结点代表的那条链，之后递归下去一次连在后面
        // 最后哪条有剩余，就将另外一条返回
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```