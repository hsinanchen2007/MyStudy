### 解题思路
大家都用数组来表示线段树。但我想了想一天还没想明白数组的下标是怎么对应到线段树上的。。。还是脑子太笨了
于是我按照自己对线段树的理解自定义了一个SegmentTreeNode类，用递归的方式绕开下标构造线段树并实现题目的要求。
结果虽然通过了，但是花了944ms。。。。以后有时间再琢磨琢磨怎么用数组下标表示线段树吧。

### 代码

```python3
import queue
class SegmentTreeNode:
    def __init__(self, l, r, parent=None):
        # [l,r]
        self.val = None
        self.parent = parent
        self.left = None
        self.right = None
        self.l = l
        self.r = r


class NumArray:

    def __init__(self, nums: List[int]):
        if len(nums) == 0:
            nums = [0]
        self.nums = nums
        root = SegmentTreeNode(0, len(self.nums))
        self.sg_tree = [root]
        self.leaves = []
        self.buildTree(root)
        # print([n.val for n in self.sg_tree])
        # print([n.val for n in self.leaves])
        

    def update(self, i: int, val: int) -> None:
        self.leaves[i].val = val
        node = self.leaves[i]
        while node.parent != None:
            node = node.parent
            node.val = node.left.val + node.right.val


    def sumRange(self, i: int, j: int) -> int:
        q = queue.Queue()
        q.put([self.sg_tree[0], i, j+1])
        Sum = 0
        while not q.empty():
            node, l, r = q.get()
            # print(l,r,node.l, node.r)
            if l == node.l and r == node.r:
                Sum += node.val
            else:
                if r <= node.left.r:
                    q.put([node.left, l, r])
                elif l >= node.right.l:
                    q.put([node.right, l ,r])
                else:
                    q.put([node.left, l, node.left.r])
                    q.put([node.right, node.right.l, r])
        return Sum


    def buildTree(self, node):
        # 递归建树
        l, r = node.l, node.r
        if r-l == 1:
            node.val = self.nums[l]
            self.leaves.append(node)
            return
        else:
            node.left = SegmentTreeNode(l, (l+r)//2, node)
            # self.sg_tree.append(node.left)
            self.buildTree(node.left)
            node.right = SegmentTreeNode((l+r)//2, r, node)
            # self.sg_tree.append(node.right)
            self.buildTree(node.right)
            node.val = node.left.val + node.right.val
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
```