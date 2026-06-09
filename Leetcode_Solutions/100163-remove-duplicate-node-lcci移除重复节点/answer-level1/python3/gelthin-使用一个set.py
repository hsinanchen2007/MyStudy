### 解题思路

相似题目： 
[83.删除排序链表中的重复元](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

[看评论，使用无序的 set 可能更快](https://leetcode-cn.com/problems/remove-duplicate-node-lcci/solution/yin-ru-setdui-yu-setzhong-bu-cun-zai-de-jie-dian-j/263621)。 
[python set 本身就无序](https://bbs.csdn.net/topics/392243663?page=1)

list 用链表实现，追加元素方便，set 使用 hash 表实现，hash 要扩容，避免冲突等。

##### 如果不是用 set(), 可以暴力在 O(n^2) 解决。
对每个 x, 遍历其后的每一个节点，如果相同，就删去。





### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if head == None:
            return
    #相似题目： 83. 删除排序链表中的重复元素
        A = set()  # 看评论，使用无序的 set 可能更快。 python set 本身就无序 
        # https://bbs.csdn.net/topics/392243663?page=1
        A.add(head.val)
        prev, p = head, head.next
        while p:
            if p.val in A:
                prev.next = p.next
                del p
                p = prev.next
            else:
                A.add(p.val)
                prev = p
                p = p.next
        
        return head
```