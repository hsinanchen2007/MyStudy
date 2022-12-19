## 解题思路
题目要求排序算法的时间复杂度为 _O(n log n)_ ，空间复杂度为 _O(n)_ ，直接想到 **归并排序**。

**归并排序** 是采用**分治法**的一种排序算法：
* **分**，就是把数列一分二，二分四...最后分成两两一组的最小子集
* **治**，就是把分开后的子集，一一排序后归并在一起

最后由局部有序成为全部有序，和数组的归并排序相比，链表多出的一步就是如何找到链表的中点？

## 解题方式
利用快慢指针找到链表的中点，利用递归的方式进行分组排序。
```
/**
     * 链表归并排序
     */
    public ListNode sortList(ListNode head) {

        if (head == null || head.next == null) {
            return head;
        }

        ListNode mid = findMiddle(head);
        ListNode right = sortList(mid.next);
        mid.next = null;

        ListNode left = sortList(head);

        return merge(left, right);
    }

    /**
     * 找出中间的节点
     */
    public ListNode findMiddle(ListNode node) {
        ListNode fast = node.next;
        ListNode slow = node;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        return slow;
    }

    /**
     * 对两组链表进行归并排序
     */
    public ListNode merge(ListNode left, ListNode right) {
        ListNode a = left;
        ListNode b = right;

        ListNode result = new ListNode(0);
        ListNode tmp = result;

        while (a != null && b != null) {
            while (a != null && a.val <= b.val) {
                tmp.next = new ListNode(a.val);
                tmp = tmp.next;
                a = a.next;
            }

            while (a != null && b != null && b.val <= a.val) {
                tmp.next = new ListNode(b.val);
                tmp = tmp.next;
                b = b.next;
            }
        }

        if (a != null) {
            tmp.next = a;
        } else if (b != null) {
            tmp.next = b;
        }

        return result.next;
    }
```