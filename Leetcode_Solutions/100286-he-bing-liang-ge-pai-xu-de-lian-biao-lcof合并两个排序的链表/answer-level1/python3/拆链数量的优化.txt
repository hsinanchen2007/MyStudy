### 解题思路
三种方法，只有拆链数量的不同

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 把l1 l2交换位置。重新连线，把小的连成一条线
        if not l1:return l2
        if not l2:return l1
        if l1.val >l2.val:
            l1,l2=l2,l1
        head=l1
        while l1.next and l2:
            if l1.next.val>l2.val:
                tmp=l2
                l2=l1.next
                l1.next=tmp
                l1=l1.next
            else:
                l1=l1.next
        l1.next=l2
        return head
        # 工作指针跳来跳去
        head=ListNode(None)
        p=head
        while l1 and l2:
            if l1.val<=l2.val:
                p.next=l1
                p=l1
                l1=l1.next
            else:
                p.next=l2
                p=l2
                l2=l2.next
        if l1:
            p.next=l1
        if l2:
            p.next=l2
        return head.next
        # 主链和从链合并，取一整段再剪切
        if not l1:return l2
        if not l2:return l1
        if l1.val >l2.val:
            l1,l2=l2,l1
        head=l1
        while True:
            while l1.next and l2.val>=l1.next.val:
                # 主链递增
                l1=l1.next
            else:
                if not l1.next:
                    # 主链走完，合并剩余从链
                    l1.next=l2
                    break
            h2=l2# 记录从链头
            while l2.next and l1.val<=l2.next.val<l1.next.val:
                l2=l2.next
            else:
                # 拼接进位
                tmp=l1.next
                l1.next=h2  
                l1=tmp
                tmp=l2.next
                l2.next=l1
                l2=tmp
                if not l2:# 注意：这里的l2是上面的l2next，从链走完，直接退出
                    break
        return head
                
```