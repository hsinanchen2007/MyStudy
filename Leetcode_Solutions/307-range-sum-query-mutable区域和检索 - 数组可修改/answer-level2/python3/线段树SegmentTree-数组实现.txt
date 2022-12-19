因为存在更新数组某个值，那么使用线段树的时间复杂度要优于**使用前缀数组和的方法** 和 **查询时直接暴力相加的方法**
线段树整个树高`O(logn)`，使得更新和查询操作都是`O(logn)`级别的
![u=1091946519,1765257349&fm=26&gp=0.png](https://pic.leetcode-cn.com/2971b5df5eba05a50650ec77e938d28689108333de3802c194b0b9982e881999-u=1091946519,1765257349&fm=26&gp=0.png)

线段树(区间树)叶子节点都是具体的值，是长度为1的区间。由满二叉树的性质:
- 最后一层节点数为$2^{h-1}$
- 树所有节点总数为$2^h-1$
- 树的所有节点数约等于最后一层节点数和其他层节点数之和

如果传入的数组`len(nums)==2的k次方`,可知此时线段树是一棵满二叉树，要对于nums，就要申请2n的空间来存储线段树，对于最坏的情况`len(nums)==2的k次方+1`，那么就需要`2n+2n=4n`的空间来存储这棵线段树(即使很多空间浪费了，空间复杂度O(n))

定位某个索引为index根节点的左孩子右孩子，就类似堆的数据结构，左孩子索引为`2*index+1`,`2*index+2`(从0开始存储)


线段树的创建，查询，更新都使用递归，理解起来比较容易
- 创建：由下至上创建根节点，两个孩子创建好以后，根据需要的业务逻辑(区间和，区间最大值，区间最小值)，来创建这两个孩子的根节点
- 查询：查询区间有可能在线段树某个节点的左半区间(左孩子)那就递归查询左孩子，**或者**右半区间(右孩子)那就递归查询右孩子，**或者**(左半右半都有一部分)，就递归查询左半部分，右半部分，然后根据业务逻辑合并返回
- 更新：如果更新位置在节点的左半区间(左孩子)，就递归更新左孩子，如果在右半区间，就递归更新右孩子。更新完成以后，里面的小区间变化了，包裹的大区间即该节点也要根据业务逻辑更新


```python
class SegmentTree:
    def __init__(self, data, merge): 
        '''
        data:传入的数组
        merge:处理的业务逻辑，例如求和/最大值/最小值，lambda表达式
        '''

        self.data = data
        self.n = len(data)
        #  申请4倍data长度的空间来存线段树节点
        self.tree = [None] * (4 * self.n) # 索引i的左孩子索引为2i+1，右孩子为2i+2
        self._merge = merge
        if self.n:
            self._build(0, 0, self.n-1)


    def query(self, ql, qr):
        '''
        返回区间[ql,..,qr]的值
        '''
        return self._query(0, 0, self.n-1, ql, qr)

    def update(self, index, value):
        # 将data数组index位置的值更新为value,然后递归更新线段树中被影响的各节点的值
        self.data[index] = value
        self._update(0, 0, self.n-1, index)

    def _build(self, tree_index, l, r):
        '''
        递归创建线段树
        tree_index : 线段树节点在数组中位置
        l, r : 该节点表示的区间的左,右边界
        '''
        if l == r:
            self.tree[tree_index] = self.data[l]
            return
        mid = (l+r) // 2 # 区间中点,对应左孩子区间结束,右孩子区间开头
        left, right = 2 * tree_index + 1, 2 * tree_index + 2 # tree_index的左右子树索引
        self._build(left, l, mid)
        self._build(right, mid+1, r)
        self.tree[tree_index] = self._merge(self.tree[left], self.tree[right])

    def _query(self, tree_index, l, r, ql, qr):
        '''
        递归查询区间[ql,..,qr]的值
        tree_index : 某个根节点的索引
        l, r : 该节点表示的区间的左右边界
        ql, qr: 待查询区间的左右边界
        '''
        if l == ql and r == qr:
            return self.tree[tree_index]

        mid = (l+r) // 2 # 区间中点,对应左孩子区间结束,右孩子区间开头
        left, right = tree_index * 2 + 1, tree_index * 2 + 2
        if qr <= mid:
            # 查询区间全在左子树
            return self._query(left, l, mid, ql, qr)
        elif ql > mid:
            # 查询区间全在右子树
            return self._query(right, mid+1, r, ql, qr)

        # 查询区间一部分在左子树一部分在右子树
        return self._merge(self._query(left, l, mid, ql, mid), 
                          self._query(right, mid+1, r, mid+1, qr))

    def _update(self, tree_index, l, r, index):
        '''
        tree_index:某个根节点索引
        l, r : 此根节点代表区间的左右边界
        index : 更新的值的索引
        '''
        if l == r == index:
            self.tree[tree_index] = self.data[index]
            return
        mid = (l+r)//2
        left, right = 2 * tree_index + 1, 2 * tree_index + 2
        if index > mid:
            # 要更新的区间在右子树
            self._update(right, mid+1, r, index)
        else:
            # 要更新的区间在左子树index<=mid
            self._update(left, l, mid, index)
        # 里面的小区间变化了，包裹的大区间也要更新
        self.tree[tree_index] = self._merge(self.tree[left], self.tree[right])
        

class NumArray:

    def __init__(self, nums: List[int]):
        self.segment_tree = SegmentTree(nums, lambda x, y : x + y)
        

    def update(self, i: int, val: int) -> None:
        self.segment_tree.update(i, val)
        

    def sumRange(self, i: int, j: int) -> int:
        return self.segment_tree.query(i, j)
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
```
