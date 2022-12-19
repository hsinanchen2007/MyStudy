 `Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.` 

这句话说得太含糊了，中文翻译更是糊涂。应该这么表达：

```
head中 多个（包含一个）连续节点 的值 都存在于G中，则 把这 多个（包含一个）连续节点 称之为一个组件。返回组件的个数；
```

再举个栗子
 `head=[0, 1, 2, 3, 4, 5, 6, 7]  G=[0, 2, 3, 4, 5, 7]` , 有[0], [2, 3, 4, 5], [7] 3个组件
 
`head=[0, 1, 2, 3, 4, 5, 6, 7]  G=[0, 2, 3, 5, 7]` , 有[0], [2, 3], [5], [7] 4个组件

附上Python3代码

```python
class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        cur, i = head, 0
        g_set = {i for i in G}
        while cur.next:
            if (cur.val in g_set) and (cur.next.val not in g_set):
                i += 1
            cur = cur.next
        # 当cur到达链表最后一个node时，如果cur.val在G里面，不过前面有多少个连续的值，
        # 都属于1个components，结果+1；如果cur.val不在G里面，就是没有components了
        if cur.val in g_set: 
            i += 1
        return i
```
把列表G转换成集合g_set, 这样if x in Y的时间复杂度就是O(1)而不是O(n)