## 思路：

这道题应该是 `Hard` 难度的（看通过率就知道了）

简单想法：维护一个长度为 `k+1`的**连续**队列， 在这队列里一定任何两个数索引号相差不会超过 `k`，当队列存在两个数相差为`t`，那么返回为 `true`

简单想法代码如下，这个一定要理解，后面只是换了数据结构！

```python
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        from collections import deque
        import bisect
        n = len(nums)
        if n <= 1: return False
        m = min(n, k + 1)
        # 维护一个长度为 k + 1 队列
        queue = sorted(nums[:m])
        # 要删除数
        to_del = deque()
        to_del.extendleft(nums[:m])
        # 先判断首先 k + 1 队列是否存在满足条件的
        for i in range(1, m):
            if queue[i] - queue[i - 1] <= t:
                return True
        for i in range(m, n):
            # 移动队列
            queue.remove(to_del.pop())
            # 二分插入
            loc = bisect.bisect_left(queue, nums[i])
            queue.insert(loc, nums[i])
            # 判断它在队列中左右两边数是否小于等于t
            if (loc - 1 >= 0 and nums[i] - queue[loc - 1] <= t) or \
                    (loc + 1 <= k and queue[loc + 1] - nums[i] <= t):
                return True
            to_del.appendleft(nums[i])
        return False
```

上面的代码也能过，但是极慢，为什么？

原因就是数组插入删除的时间复杂度为 $O(n)$，有没有一种数据结构**又能排好序**，然而**删除添加的时间复杂度有很少**呢？$log(n)$

当然有了，那就是二叉排序树（BST）`Python`没有自带的库， `Java`里有 `TreeSet`

但是可以自己实现，网上找到的代码，大家感兴趣研究一下，（哭！不想看，后面还有一个桶排序要看一下啊！

```python
from collections import deque

class BSTNode:
    
    def __init__(self, dlnode):
        self.ptr = dlnode
        self.l = None
        self.r = None


class BST:
    
    def __init__(self, head):
        self.root = BSTNode(head)
    
    def insert(self, dlnode):
        
        def insertHelper(root, dlnode, min_, max_):
            if dlnode.v <= root.ptr.v:
                if not root.l:
                    root.l = BSTNode(dlnode)
                    if min_:
                        min_ = min_.ptr
                    return min_, root.ptr
                return insertHelper(root.l, dlnode, min_, root)
            else:
                if not root.r:
                    root.r = BSTNode(dlnode)
                    if max_:
                        max_ = max_.ptr
                    return root.ptr, max_
                return insertHelper(root.r, dlnode, root, max_)
        
        return insertHelper(self.root, dlnode, None, None)
    
    def delNode(self, node):
        tmp, prev = self.root, None
        while tmp and node != tmp.ptr:
            prev = tmp
            if node.v <= tmp.ptr.v:
                tmp = tmp.l
            else:
                tmp = tmp.r
        
        if tmp == None:
            return f'Something went wrong, Node {node} not found...'
        else:
            if tmp.l and tmp.r:
                tmp2, prev2 = tmp.r, None
                while tmp2.l:
                    prev2 = tmp2
                    tmp2 = tmp2.l
                
                if prev2:
                    prev2.l = tmp2.r
                
                if prev:
                    if prev.l == tmp:
                        prev.l = tmp2
                    elif prev.r == tmp:
                        prev.r = tmp2
                    else:
                        return 'Something went wrong.'
                else:
                    self.root = tmp2
                
                tmp2.l = tmp.l
                if tmp2 != tmp.r:
                    tmp2.r = tmp.r
            elif tmp.l:
                if prev:
                    if prev.l == tmp:
                        prev.l = tmp.l
                    elif prev.r == tmp:
                        prev.r = tmp.l
                    else:
                        return 'Something went wrong.'
                else:
                    self.root = tmp.l
            elif tmp.r:
                if prev:
                    if prev.l == tmp:
                        prev.l = tmp.r
                    elif prev.r == tmp:
                        prev.r = tmp.r
                    else:
                        return 'Something went wrong.'
                else:
                    self.root = tmp.r
            else:
                if prev:
                    if prev.l == tmp:
                        prev.l = None
                    elif prev.r == tmp:
                        prev.r = None
                    else:
                        return 'Something went wrong.'
                else:
                    self.root = tmp.r
            
            del tmp
    
    def popByorder(self):
        def inorderPop(root):
            nodes = []
            
            if root.l:
                nodes += inorderPop(root.l)
            nodes += [root.ptr]
            if root.r:
                nodes += inorderPop(root.r)
            
            return nodes
        
        return inorderPop(self.root)
    
    def __str__(self):
        def inorder(root):
            s = ''
            
            if root.l:
                s += inorder(root.l)
            s += f' -> {root.ptr.v}'
            if root.r:
                s += inorder(root.r)
            
            return s
        
        return 'BST' + inorder(self.root)

class DLNode:
    
    def __init__(self, v):
        self.v = v
        self.next = None
        self.prev = None
        
class DList:
    
    def __init__(self, v):
        self.head = DLNode(v) if isinstance(v, int) else v
        self.tail = self.head
    
    def append(self, node):
        if self.head == self.tail:
            self.head.next = node
        self.tail.next = node
        node.prev = self.tail
        self.tail = node
    
    def insert(self, l, m, r):
        if l and r:
            l.next = m
            m.next = r
            r.prev = m
            m.prev = l
        elif l:
            self.tail = m
            l.next = m
            m.prev = l
        elif r:
            self.head = m
            m.next = r
            r.prev = m
    
    def delHead(self):
        tmp = self.head
        self.head = self.head.next
        self.head.prev = None
        del tmp
    
    def delTail(self):
        tmp = self.tail
        self.tail = self.tail.prev
        self.tail.next = None
        del tmp
    
    def delNode(self, d):
        if d == self.head:
            self.delHead()
        elif d == self.tail:
            self.delTail()
        else:
            d.prev.next = d.next
            d.next.prev = d.prev
            del d
    
    def __str__(self):
        s = f'{self.head.v}'
        tmp = self.head.next
        while tmp:
            s += f' -> {tmp.v}'
            tmp = tmp.next
        return s

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if not nums or k == 0:
            return False

        n = len(nums)
        m = DLNode(nums[0])
        bst = BST(m)
        toDel = deque([m])
        for x in nums[1:k + 1]:
            m = DLNode(x)
            _, _ = bst.insert(m)
            toDel.append(m)

        for i, m in enumerate(bst.popByorder()):
            if i == 0:
                dl = DList(m)
            else:
                dl.append(m)

        i, j = dl.head, dl.head.next
        while j:
            if j.v - i.v <= t:
                return True
            i = i.next
            j = j.next

        if k < n:
            for x in nums[k + 1:]:
                d = toDel.popleft()
                bst.delNode(d)
                m = DLNode(x)
                l, r = bst.insert(m)
                if (l and m.v - l.v <= t) or (r and r.v - m.v <= t):
                    return True
                toDel.append(m)
        return False
```

是的，还有一种思路，**桶排序**[^1]

大家自行用例子模拟，感觉一下！

时间复杂度：$O(n)$

```python
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        from collections import OrderedDict
        n = len(nums)
        if n <= 1 or k < 1 or t < 0: return False
        queue = OrderedDict()
        for n in nums:
            key = n if not t else n // t
            for m in [queue.get(key-1), queue.get(key), queue.get(key+1)]:
                if m is not None and abs(n - m) <= t:
                    return True
            if len(queue) == k:
                queue.popitem(False)
            queue[key] = n
        return False
```



[^1]: https://leetcode.com/problems/contains-duplicate-iii/discuss/61756/Python-OrderedDict