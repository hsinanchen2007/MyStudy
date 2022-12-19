* 建立哑结点`dummy`，当前处理节点为`curr`，它的值为`anchor`，它的前序节点为`prev`。
* 如果`curr`的后序节点的值等于`anchor`，那么标注`flag`为`True`，`curr`一直后移下去，总之，`curr`移到连续的最后一个值为`anchor`的节点，停下来。如果经历了上述步骤，那么`prev`和`curr.next`相连，`prev`按兵不动，`curr`后移一位；如果没有经历，`curr`的值是独一无二的，那么`prev`和`curr`同时右移一位。继续循环直到`curr`移到最后一位。
* 不难，但是要注意细节，保持头脑清醒。
* 时间复杂度: O(n), 空间复杂度: O(1)

```python []
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head

        prev = dummy
        curr = head
        while(curr):
            anchor = curr.val
            flag = False
            while(curr.next):
                if curr.next.val == anchor:
                    flag = True
                    curr = curr.next
                else:
                    break
            if flag: # if duplicates, relink
                prev.next = curr.next
            else: # if single, move prev
                prev = curr
            curr = curr.next
        return dummy.next
```