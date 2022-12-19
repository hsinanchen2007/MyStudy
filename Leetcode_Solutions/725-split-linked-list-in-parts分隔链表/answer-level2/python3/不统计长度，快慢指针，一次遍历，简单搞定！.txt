看了很多题解都需要先统计长度，然后求除法和余数取出结果。
这题可以灵活应用快慢指针的办法，一次遍历搞定。特别的地方是：快指针跑到尾部之后，速度减一，然后回到慢指针处继续跑，这样子就能取出来题目要求的各个分区链表。还有，为了断开链表方便，慢指针会在快指针的前一个哑节点处起跑。

代码相当简单！

```
class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        res, dummy = [], ListNode(0)
        while k > 1:
            slow = dummy
            slow.next = fast = root
            while fast:
                slow = slow.next
                for _ in range(k): 
                    if fast: fast = fast.next
            new_root = slow.next
            slow.next = None
            res.append(root)
            root = new_root
            k -= 1
        res.append(root)
        return res
```
