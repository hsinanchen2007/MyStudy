
## 滑动窗口思想

读完了这道题目,注意一个点,就是只要是重复元素,就要删掉所有,而且链表是排序的,也就是说重复元素肯定是连在一起的。所以我的思路如下：

1. 首先定义两个指针，一个指向为重复元素的前一个元素，称为left，这样做的原因是因为如果遍历链表在去判断的话，一旦碰到这一块重复元素，还需要在去遍历一次获取他们的前一个元素，才能将他们去除，所以我直接就定义一个指针。另一个就是left指针的下一个元素，用来寻找重复的元素。
2. 定义一个count变量，初始值为0，用来记录是否是重复元素，如果count为0，则不是，否则就是重复元素。
3. 因为链表头也可能是重复元素,所以要给链表添加一个边界头.

![GTVNKP.png](https://pic.leetcode-cn.com/a463c3aa7514e55b935f2b6390b500e1142a431834cfdb48291200f41dc64c0f.png)

```python
# 思路有点像滑动指针
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        new_head = ListNode(-1)
        new_head.next = head
        left = new_head
        while left and left.next:
            right = left.next
            count = 0
            # right指针移动
            while right.next and right.val == right.next.val:
                right = right.next
                count += 1
            # 证明是right指针重复元素
            if count != 0:
                right = right.next
            # 删除重复的元素
            left.next = right
            if count == 0:
                # right指针不是重复元素,则需要将left移动一个单位
                left = left.next
        return new_head.next
```


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        new_head = ListNode(-1)
        new_head.next = head
        left = new_head
        while left and left.next:
            right = left.next
            count = 0
            while right.next and right.val == right.next.val:
                right = right.next
                count += 1
            if count != 0:
                right = right.next
            left.next = right
            if count == 0:
                left = left.next
        return new_head.next
```