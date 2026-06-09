### 好像以前写过这个，大体上就是快慢指针的事情。。。当快的跑到最后的时候慢的就是要的结果

```python3
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        target_node = head                      # 慢指针
        fast_node = head                        # 快指针
        steps = 0                               # 记录快指针的步数
        while fast_node:                        # 到尾结点时退出循环
            fast_node = fast_node.next          # 快指针移动一步
            if steps>=k:                        # 慢指针开始移动条件判断
                target_node = target_node.next  # 慢指针移动一步
            steps += 1                          # 累加步数
        return target_node.val                  # 返回目标节点的值
```

208 / 208 个通过测试用例
状态：通过
执行用时：32 ms
内存消耗：13.7 MB
