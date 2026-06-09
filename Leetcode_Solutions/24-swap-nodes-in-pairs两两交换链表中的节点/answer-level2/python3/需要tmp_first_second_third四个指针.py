### 解题思路
维持三个节点
tmp>first>second>third
其中fisrt和fist.next用于遍历
其中tmp是first的上一个节点

每次先进行first和second的变换，得到tmp>second>first>third
然后更新curr = first，即新的前一个节点
然后更新first=third，进入下一对的开头

另外有可能只有1个节点，那么开头的dummpy的next直接设置成head节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummpy = ListNode(None)
        dummpy.next = head

        curr = dummpy

        first = head
        while first and first.next:
            second = first.next
            third = second.next

            # 交换
            curr.next = second
            second.next = first
            first.next = third

            # 延续队列
            curr = first
            
            # 重新定位
            first = third
           
        return dummpy.next

        
```