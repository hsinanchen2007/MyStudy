### 1.解法一：两次变比法

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        # 5 - 2 ==> 3
        # 从head再数3个即可
        # Step 1: get length
        dummyHead = head
        count = 0
        while dummyHead != None:
            dummyHead = dummyHead.next
            count += 1
        print(count)
        # Step 2: 计算正着走需要多少步
        steps = count - k
        while head != None and steps != 0:
            head = head.next
            steps -= 1
        return head
```

倒数是第k个，那么正着数呢？

这种需要两次遍历。

### 解法二：一次遍历，双指针法

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        # 一次遍历，双指针法
        ptr_1, ptr_2 = head, head
        while ptr_2 != None and k != 1:
            ptr_2 = ptr_2.next
            k -= 1
        while ptr_2.next != None:
            ptr_1 = ptr_1.next
            ptr_2 = ptr_2.next
        return ptr_1     
```

注意第二个指针是先走k-1步，然后判断结束是第二个指针.next为空。

这些都可以通过样例来测试。

END.