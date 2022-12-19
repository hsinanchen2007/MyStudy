### 解题思路
双指针 注释都有

整体思路就是数组的双指针一样。
只不过就是多了些 边界判断
### 代码

```python3

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return None
        # 给定一个排序链表，删除所有含有重复数字的节点，
        # 只保留原始链表中 没有重复出现 的数字。
        # 这个也是使用双指针
        # 把所有重复的元素都要删除掉 emmm确实有难度啊
        virtual = ListNode(-1)
        ans = virtual
        while head:
            # 设置双指针
            tmp = head
            while tmp.next and tmp.val == tmp.next.val:
                tmp = tmp.next
            # 此时tmp达到了相等情况时的最后一个位置
            # 两个的地址相同的话 说明就是同一个！
            # 可见我的思路是对的！
            if head == tmp:
                virtual.next = head
                # head.next = None
                virtual = virtual.next
            head = tmp.next
        virtual.next = None
        return ans.next

```