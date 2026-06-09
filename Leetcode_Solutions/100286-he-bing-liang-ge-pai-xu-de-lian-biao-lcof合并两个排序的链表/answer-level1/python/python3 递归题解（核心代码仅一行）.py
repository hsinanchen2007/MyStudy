> *如果你的题解无人问津，为什么不试试换个标题...    --Xun Lu*

&nbsp;
### 分析
很适合用**递归进行求解**。
首先判断l1或者l2为空的情况：
1. `l1`为空的话，把`l2`剩下的返回就行了。
2. `l2`为空的话，把`l1`剩下的返回就行了。
3. 都为空返回空，为了少写一行代码，就返回`l1`.

上面的既是空的情况的判断，也是递归结束的条件。

### 代码
如果`l1`的头结点值比较小，那么这次应该取``，也就是：

```python3
mergeHead = l1
```

剩下`l1.next` 和`l2`再进行相同的操作,得到mergeHead的下一个节点:
```python3
mergeHead.next = self.mergeTwoLists(l1.next, l2)
```
省略中间变量`mergeHead`，合并起来就是我下面完整版的鬼畜模样了。（***牺牲了一点可读性，并不是很建议在面试中使用***
```
l1.next = self.mergeTwoLists(l1.next, l2)
```

最后，两个if 可以用个交换合并。

### 完整版代码

```
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None: return l2
        if l2 is None: return l1
        if l1.val > l2.val: l1,l2 = l2,l1
        l1.next = self.mergeTwoLists(l1.next, l2)
        return l1
       
```
