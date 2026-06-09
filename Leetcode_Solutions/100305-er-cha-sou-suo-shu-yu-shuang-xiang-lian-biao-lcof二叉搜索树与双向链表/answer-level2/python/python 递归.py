### 解题思路
第一步：需要把 left 指针指向上一个比该元素小的值， right 指针指向下一个比当前元素大的值。但是这个值不一定是该节点的父亲或者儿子。所以递归的时候需要传递当前元素已知的界限给儿子。

而且传给左孩子的右界限是自己，左界限是当前元素的父亲传下来的界限。给右孩子的则正好相反。

递归的起始根节点的左右界限都设为 None

第二步：把最小值和最大值连接起来

如何找到最小值和最大值，最小值和最大值**不一定**是叶子节点。我刚开始犯了这个错误。

最小值一定是某个节点的左儿子，而且他没有左儿子。是整个树最左边的左儿子。

所以我定义的找最小节点的条件是：没有左儿子 + 父亲传来的左界限为 None
最大节点：没有右儿子 + 父亲传来的右界限为 None

### 代码

```python3
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root: return root
        def build(t, l, r):
            # print(t.val, t.left, t.right, l, r)
            xl = t if not l else l
            xr = t if not r else r
            xxl, xxr = t, t
            if not t.left:
                if not l:
                    self.head = t
                else:
                    t.left = l
            else:
                ll, lr = build(t.left, l, t)
                t.left = lr
                xxl = ll

            if not t.right:
                if not r:
                    self.rear = t
                else:
                    t.right = r
                
            else:
                rl, rr = build(t.right, t, r)
                t.right = rl
                xxr = rr
            return xxl, xxr
        build(root, None, None)
        self.head.left = self.rear
        self.rear.right = self.head
        return self.head
```