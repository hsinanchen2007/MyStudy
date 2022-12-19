![IMG_1634](https://pic.leetcode-cn.com/2cff0110538948ae45828328cfc6e4340cb1b9206731f7f934da517e5725513a.jpg)

### 思路

- 标签：`递归`
- 从最小的节点开始，将剩下的链表节点看成一个节点
- 基准条件：某一个链表为空。此时返回另个一个链表的剩余有序节点
- 时间复杂度：O(M+N)，最差为两个链表的长度
- 空间复杂度：O(1)

### 代码


```Python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
```
```Java []
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
        if(l1 == null) {
            return l2;
        }
        if(l2 == null) {
            return l1;
        }

        if(l1.val <= l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```

### 画解

部分图片来源于：https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/hua-jie-suan-fa-21-he-bing-liang-ge-you-xu-lian-bi/。

作者：guanpengchn

<![IMG_1634](https://pic.leetcode-cn.com/23b51505170862cade04974a77bb89a572b949b1e87cfdcaf2259d7a370acf73.jpg),![img](https://pic.leetcode-cn.com/f1e3e7b5745a8effbf4831d6b988d9a2d480c990a462495c3cc8a9bd6ada1237.jpg),![img](https://pic.leetcode-cn.com/e23303e11c53b766dfb5478d50fc5dfdd375abe776e64e0b0dbaeff9939ae9dc.jpg),![img](https://pic.leetcode-cn.com/7a8cb139a68f0eeb08839a64bcbe4188a4e017deda97e454e76a0f83e650cedc.jpg)>

