整体时间复杂度为O(N*log(k)), k为链表个数，N为链表数组中节点总个数。
整体思路为
1. 合并数组中第k个链表到第1个链表，合并数组中第k-1个链表到第2个链表，依次这样操作...

![lc23.png](https://pic.leetcode-cn.com/3bbacd54470d7bf622cf4ab677cdeddce44463e9d50c8b740a7f87cc294b7199-lc23.png)

2. 一轮合并之后，新链表分布在数组的 第1 到 第(k+1)/2个链表中，继续1这样的合并直到新链表只在数组第一个位置。
3. 返回数组第一个元素，即合并之后的链表。

```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int len = lists.length;
        if (len == 0) {
            return null;
        }    
        // 将n个链表以中间为对称，合并，即合并 
        while(len>1) {
            for (int i=0; i<len/2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
            }
            len = (len+1)/2;
        }
        return lists[0];
    }
    
    // 合并两个链表
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(-1);
        ListNode p = head;
        while(l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                p.next = l1;
                l1 = l1.next;
            } else {
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }
        if (l1 != null) {
            p.next = l1;
        } else if (l2 != null) {
            p.next = l2;
        }
        return head.next;
    }
}
```
