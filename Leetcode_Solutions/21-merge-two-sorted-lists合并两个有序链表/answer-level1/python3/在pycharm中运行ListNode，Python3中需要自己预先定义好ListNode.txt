### 解题思路
在leetCode内部应该是预先定义好python中的ListNode类型数据，所以代码可以直接运行。而同样的代码在Pycharm中无法运行，会提示没有val方法。
解决方案：自己定义ListNode类型，且初始化节点，以下被注释掉的代码是在pycharm中可以运行的完整代码。

### 代码

```python3 
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# def mergeTwoLists(l1, l2):
#     if l1 is None:
#         return l2
#     elif l2 is None:
#         return l1
#     elif l1.val < l2.val:
#         l1.next = mergeTwoLists(l1.next, l2)
#         return l1
#     else:
#         l2.next = merge(l1, l2.next)
#         return l2

# # 初始化所有ListNode，L1=[1,2,4], L2=[1,3,4]
# l1_1 = ListNode(1)
# l1_2 = ListNode(2)
# l1_3 = ListNode(4)
# l1_1.next = l1_2
# l1_2.next = l1_3

# l2_1 = ListNode(1)
# l2_2 = ListNode(3)
# l2_3 = ListNode(4)
# l2_1.next = l2_2
# l2_2.next = l2_3

# l3 = merge(l1_1, l2_1)
# result = []
# while(l3 != None):
#     result.append(l3.val)
#     l3 = l3.next
# print(result)


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        elif l2 is None:
            return l1
        elif l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2

```