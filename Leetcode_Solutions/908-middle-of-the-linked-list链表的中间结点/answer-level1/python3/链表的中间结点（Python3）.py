#### 思路
遍历一遍链表，将其保存在数组`tmp_list`中，中间结点的索引为`len(tmp_list) // 2`，将指针移到该位置即可。
#### 代码
```
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if head.next == None: # 考虑边界情况
            return head
        if head.next.next == None:
            return head.next
        # 定义保留头节点
        tmp = head
        tmp_list = []
        while tmp:
            tmp_list.append(tmp)
            tmp = tmp.next
        return tmp_list[len(tmp_list) // 2]
```
#### 复杂度分析
- 时间复杂度：$O(N)$，N为链表的长度，我们遍历了一遍链表，遍历了一半长度的数组
- 空间复杂度：$O(N)$，使用了数组`tmp_list`来确定中间位置

![白色背景关注.jpg](https://pic.leetcode-cn.com/6c18bb76abad971a2db54a010561f44fd1445ca10f9b671ecfee1a7df2482c08-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
