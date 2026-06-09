给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

    输入: head = 1->4->3->2->5->2, x = 3
    输出: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list


### 解题思路
#### 快排思想
这个题的思路很符合快排中选择哨兵之后围绕哨兵进行排序的思想。其中x是哨兵。

我们建立两个大小链表，遍历原始链表。比哨兵小的追加小链表s，大于等于x的追加到链表b。

最后将大链表b链接到小链表中

##### Python
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        s, b = ListNode(0), ListNode(0)
        cur, scur, bcur = head, s, b 
        while cur:
            if cur.val < x:
                scur.next = ListNode(cur.val)
                scur = scur.next
            else:
                bcur.next = ListNode(cur.val)
                bcur = bcur.next
            cur = cur.next
        scur.next = b.next
        return s.next
```

##### Java
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
    public ListNode partition(ListNode head, int x) {
        ListNode s = new ListNode(0);
        ListNode b = new ListNode(0);
        ListNode cur = head;
        ListNode scur = s;
        ListNode bcur = b; 
        while(cur != null){
            if(cur.val < x){
                scur.next = new ListNode(cur.val);
                scur = scur.next;
            }
            else{
                bcur.next = new ListNode(cur.val);
                bcur = bcur.next;
            }
            cur = cur.next;
        }
            
        scur.next = b.next;
        return s.next  ;
    }
}
```


