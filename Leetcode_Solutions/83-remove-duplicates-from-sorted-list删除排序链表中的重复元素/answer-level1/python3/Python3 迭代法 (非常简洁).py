### 解题思路
1. 设置 cur = head
2. 当 cur 以及 cur.next 不为 None 的时候, 不断进行迭代. 此处可以考虑为: 如果 cur.next 为 None 说明已经到了 链表最后一个元素,故停止判断.
3. 条件判断: 如果 cur.next.val == cur.val, 说明下一个元素和当前元素是重复的,那么直接链接到 下下一个元素(此时假如下下一个元素依然等于当前元素, 也就是说, cur 和 cur.next 依然相等,所以 cur 会继续链接到其下一个,最终去除掉所有重复元素); 当下一个元素不重复就很好理解了,直接链接.
4. 最后返回 head, 而不是 cur. 为什么呢? 假如对于 链表 1->2->2->3, 结束后, 若返回 cur, 那我们会得到 3, 如果返回 head 我们会得到 1,2,3; 所以很明显我们是要返回 head. 原因是, head 依旧是 我们要返回的 链表的 头部节点, 而 cur已经是当前节点了, 也即尾部节点. 实际上我们是通过 cur 来操作了链表的每一个节点. 最后通过头部节点返回整个链表.
(本人是算法小白,有同学若发现不当之处,望留言指正)

### 代码

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        cur = head
        while cur and cur.next:
            if cur.next.val == cur.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head
```