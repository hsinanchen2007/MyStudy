### 解题思路
![1580804084(1).png](https://pic.leetcode-cn.com/3746cf145c270873a44dd1a891e5171b612605bfa526315e8651213abfc78310-1580804084\(1\).png)
算法总循环次数就是两条链表中最大的长度。
具体思想：无论哪条链表更长，总把相加之后的值赋予l1链表，同时记录是否进位。当有链表已经为None时，若l2为None，l1非空则遍历剩余节点判断是否进位，以及最后是否添加一个新节点；若l1已经到了结尾，l2非空，则把l2剩余节点接到l1后，遍历l2剩余节点，做法同上；若均已结尾，判读是否需要进位构造新节点。
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        enter=0
        track1=l1
        track2=l2
        while track1 is not None and track2 is not None:
           sum=track1.val+track2.val+enter
           enter=0
           if sum>=10:
               track1.val=sum-10
               enter=1
           else:
               track1.val=sum
           pre_Node=track1
           track1 = track1.next
           track2 = track2.next
        while track1 is not None:
            if track1.val+enter<10:
                track1.val=track1.val+enter
                return l1
            else:
                track1.val=0
                enter=1
                pre=track1
                track1=track1.next
                if track1 is None:
                    temp=ListNode(1)
                    pre.next=temp
                    return l1
        if track2 is not None:
            pre_Node.next = track2
            pre_Node = pre_Node.next
        while track2 is not None:
            if pre_Node.val+enter<10:
                pre_Node.val=pre_Node.val+enter
                return l1
            else:
                pre_Node.val=0
                enter=1
                pre=pre_Node
                pre_Node=pre_Node.next
                if pre_Node is None:
                    temp=ListNode(1)
                    pre.next=temp
                    return l1
        if enter==1:
            temp = ListNode(1)
            pre_Node.next=temp
        return l1

        
```