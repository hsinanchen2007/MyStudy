给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

    输入: 1->2->3->4->5->NULL, k = 2
    输出: 4->5->1->2->3->NULL
    解释:
    向右旋转 1 步: 5->1->2->3->4->NULL
    向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

    输入: 0->1->2->NULL, k = 4
    输出: 2->0->1->NULL
    解释:
    向右旋转 1 步: 2->0->1->NULL
    向右旋转 2 步: 1->2->0->NULL
    向右旋转 3 步: 0->1->2->NULL
    向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list




### 解题思路
#### 暴力法
先遍历获得链表的长度以及链表尾部的指针（引用），然后头尾拼接起来。 随后我们只要从头遍历**k - k % length**步就能够找到旋转后链表的头指针，断开尾指针和头指针，返回头指针。

##### Python
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None:
            return None
        cur = head 
        length = 1
        while cur.next:
            cur = cur.next
            length += 1
        cur.next = head
        k = length - k % length
        while k:
            k -= 1
            cur = cur.next
        head = cur.next
        cur.next = None
        return head
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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null)
            return null;
        ListNode cur = head;
        int length = 1;
        while(cur.next != null){
            cur = cur.next;
            length ++;
        }
        cur.next = head;
        k = length - k % length;
        while(k > 0){
            k -= 1;
            cur = cur.next;
        }
        head = cur.next;
        cur.next = null;
        return head ;
    }
}
```
