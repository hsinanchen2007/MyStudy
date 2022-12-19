### 解题思路
基于 习题 [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)
童老师算法课程分治法讲过此题，还比较了 两两合并 和 逐一合并 的速度。
我最开始的想法受到了题 264. 丑数 II 的影响，每次从 k 个链表中选出最小的，然后对应指针前进一位，代码也不好写，效率极低。

官方题解非常好，有非常细致的分析。

+ 两两合并 O(n*logk)， 第一个和第二个合并，第三个和第四个合并，有点像锦标赛排序的感觉。
+ 逐一合并 O(n*k), 第一个和第二个合并，然后合并后的结果和第三个合并
+ 每次从 k 个中选最小的 O(n*k)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # 童老师算法课程讲过此题，还比较了 两两合并 和 逐一合并 的速度。
        # 我最开始的想法受到了题 264. 丑数 II 的影响，每次从 k 个链表中选出最小的，效率极低。

        def merge_2_list(a1, a2):  # 合并两个链表
            prehead = ListNode(-1)
            prehead.next = None
            prev_node = prehead
            while a1 != None and a2 != None:
                if a1.val <= a2.val:
                    prev_node.next = a1
                    prev_node = a1
                    a1 = a1.next
                else:
                    prev_node.next = a2
                    prev_node = a2
                    a2 = a2.next
            if a1 != None:
                prev_node.next = a1
            if a2 != None:
                prev_node.next = a2
            return prehead.next
        if len(lists) == 0:
            return None
        new_lists = lists
        while len(new_lists) >=2:
            result = []
            i = 0
            while i<len(new_lists)-1:  # 每两个两个进行合并
                result.append(merge_2_list(new_lists[i], new_lists[i+1]))  # 两个两个合并，这样更快
                i += 2
            if i<len(new_lists):  # 最后一段不要管忘了加入进去
                result.append(new_lists[i])
            new_lists = result
        return new_lists[0]
```

### 错误的代码
``` python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        m = len(lists)
        if m == 0:
            return None
        if m == 1:
            return lists[0]
        p = [x for x in lists]  # p[i] 表示第 i 个链表上的 pointer, 初始化为 header
        prev_head = ListNode(-1) #很奇怪，我之前似乎代码没写此，也对 
        #但这次报错，TypeError: __init__() missing 1 required positional argument: 'x'
        prev_head.next = None
        prev_node = prev_head
        while any(p):  # 有一个不为 None
            j = 0
            while j<len(lists): # 初始化找一个不为 None, 这里似乎可以增量更新，没必要每次都搜索
                if p[j]:
                    break
                j += 1
            if j == m-1: # 若仅剩一个，可以不用比较，但还是下面一个一个累加. 但若剩下的是中间的某一个，起不到作用。
                prev_node.next = p[m-1]
                break

            new_node = ListNode(0) # 默认 0 
            new_node.next = None  # 初始化为 None
            prev_node.next = new_node

            for i in range(j+1, m):  
                if p[i] != None and p[i].val < p[j].val:
                    j = i
            new_node.val = p[j].val
            p[j] = p[j].next
            prev_node = new_node

        return prev_head.next

```