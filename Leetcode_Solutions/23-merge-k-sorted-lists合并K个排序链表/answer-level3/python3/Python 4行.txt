```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        r, n, p = [], lists and lists.pop(), None
        while lists or n: r[len(r):], n = ([n], n.next or lists and lists.pop()) if n else ([], lists.pop())
        for n in sorted(r, key=lambda x: x.val, reverse=True): n.next, p = p, n
        return n if r else []
```
- 本题思路：
	1. 把题目给的所有链表中的所有节点放进一个列表 r。
	2. 对这个列表 r 中的所有节点进行从大到小的排序。O(NlogN)
	3. 把每个节点的指针指向前一个节点。（第一个节点，也就是最大的那个，指向None。）
	4. 返回最后一个节点，也就是整个新链表的开头。

- 如何把所有节点放进 r(result link)？

	我们首先初始化 r 为空列表，初始化 n(node) 为题目所给的第一个链表的开头节点，并删除lists中的这个节点，接着进入while循环，如果 n 不为空，那么 r += [n]，这里使用了切片的技巧（r[len(r):]=[n]相当于r=r+[n]），n=n.next，如果n是第一个链表的最后一个节点的话n.next就是None，下一次while的时候如果lists不为空就说明还有别的链表，此时n为None，我们让 r 不变，n=lists.pop()，也就是从lists中再取下一个节点赋值给n，重复以上步骤直到 lists 为空，我们就把所有节点放进 r 了。
	
- 怎么对 r 排序？

	用了sorted函数，其中key定义了排序时用来比较的是每个元素的val属性，同时设置reverse为True代表降序排序。
	
- 如何修改每个节点的指针？

	我们初始化 p(previous node) 为None。遍历降序排好的列表 r，r中的第一个元素就是值最大的元素，也就是我们应该返回的链表的结尾，我们设置它指向None，然后让p=这个节点，继续for循环。之后每经过一个节点 n 就把这个节点的next属性设置为上一个节点 p，遍历完成之后的 n，也就是我们遍历经过的最后一个元素，拥有最小的值，自然就是整个新链表的起始节点，我们将其作为输出值，函数返回。
