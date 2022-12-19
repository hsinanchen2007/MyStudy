### 解题思路
这是***上原题，双指针， p_n > p 相隔距离为 n, 然后 p 走到头，p_n 就恰好走到要处理的节点

同习题 [面试题 02.02. 返回倒数第 k 个节点](https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/solution/gelthin-kuai-man-zhi-zhen-by-gelthin/)

不过这一题涉及到删除操作
1. 可以少走一步，达到要删除的节点的上一个节点就停止。但注意两个指针仍然相隔 k 个距离。
2. 需要判断是否是删除头节点，需要额外处理。
3. 如果想把删除头结点和删除中间节点统一处理，可以设置一个虚拟头结点。参见官方题解[删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-by-l/)


易错点：
1. 1->2->3 如果 n=3, 就是删除第一个, 初始化p=head, 然后往前走3步到头了就是 None, p.next 则不存在。
因此需要加一个判断 p == None

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        p = head
        for i in range(n):
            p = p.next
        if p == None:
            return head.next
        p_n = head 
        while p.next != None:  # 这里相当于少走一步，而不是 p != None
            p = p.next
            p_n = p_n.next
        A = p_n.next.next
        del p_n.next
        p_n.next = A

        return head
```