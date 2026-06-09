### 解题思路
思路：
我在看到这道题的时候，我发现，k：是倒数第k个节点是新链表的最后一个节点，所以我得实现**1.倒数找节点的方法**，接着，**2.旧链表的最后一个节点肯定连着就链表的头节点**，**3.新链表的尾节点是倒数第k个节点i，倒数第k-1个节点（i.next）是新链表的头节点**， 又发现，**4.k对lenth取余后是实际的移动长度**
实现：
1. 首先得到遍历得到列表长度lenth，顺便解决**2**，得到就旧链表的尾节点
2. 从头遍历 lenth - k - 1 就能找到第k节点
3. 重设新的头节点，尾节点
4. k = k % lenth, 减少重复计算

*为什么我提交的时间复杂度好高？？击败了10%，大神们的题解在哪里哦？？？*

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        '''
        
        输入: 1->2->3->4->5->NULL, k = 2
        输出: 4->5->1->2->3->NULL
        '''
        if head is None: return None
        if k == 0 or head.next is None: 
            return head

            
        p = head  # to calulate the lenth 
        q = head  # the target node, q.next is the new head 

        lenth = 1  # because the haed is not None
        while p.next is not None:
            lenth += 1
            p = p.next
        # p.val -> 5
        # print("lenth:{}".format(lenth))


        k = k % lenth 
        if k == 0: 
            return head

        cnt = lenth - k - 1
        '''
        # 44 ms	13.6 MB
        while cnt:            
            q = q.next
            cnt -= 1
            '''
        
        # 64 ms	13.6 MB
        for _ in range(cnt):
            q = q.next

        # print("q.val:{}".format(q.val))
        '''
        find the end, but when we find the lenth, the p is the end point
        while k:
            q = q.next
            k -= 1
        '''
        p.next = head # 5->1
        head = q.next # 4-> head
        q.next = None # 3 -> None

        return head





```