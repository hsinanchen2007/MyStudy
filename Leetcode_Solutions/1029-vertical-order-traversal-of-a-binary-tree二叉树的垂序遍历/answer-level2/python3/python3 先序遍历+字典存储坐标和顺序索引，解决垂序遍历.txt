既然是垂序遍历，一个直观的想法就是保存每个结点的x、y坐标
但是这里要注意，我们还应该顺便保存结点在树中出现的**顺序索引index**（下边会解释～）
借助一个字典，进行一次先序遍历我们就可以将所有结点和对应的位置进行保存。
最后对字典做一次遍历，按一定顺序存储答案即可。

此处，“按一定顺序存储”是这道题容易出错的地方；按题意，这个“顺序”需要考虑3个规则：
（**1）按 x 从小到大排序（即垂直地从左往右遍历）**
（**2）x 相同时，按 y 从小到大存储，但因为这儿y是负值，实际上应该是按 y 从大到小存储**（比如有 a:(1,-1), b:(1,-2) 两个结点，应该先存储a，因为a在遍历时先被访问到了）
（**3）x、y 都相同时，按结点的val值从小到大存储**

这也是代码中需要根据三个指标进行排序的原因了。（没明白的同学可以再读一读题，画个草图，就应该理解啦）
```
dd = sorted(self.d.items(), key=lambda x: (x[1][0], -x[1][1], x[0].val)) # python 排序函数可以很方便的一次写多个条件～
```
其余部分都是一些常规处理，应该读代码就ok～
```
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:

        # 字典d的key存放结点，value存放该结点的x、y坐标以及按先序遍历被访问到的index
        self.d = {} # node: (x, y, index)
        
        def dfs(root, x, y, idx):
            if not root:
                return 
            self.d[root] = [x, y, idx]
            dfs(root.left, x-1, y-1, idx+1)
            dfs(root.right, x+1, y-1, idx+2)
        dfs(root, 0, 0, 0)

        # 排序细节，容易出错！
        # 1.按 x 从小到大排，相当于从左向右垂直遍历树
        # 2.按 y 从大到小排，即当x坐标相同时先出现的点（y更大）先加入列表
        # 3.当x，y都相同时（即坐标完全一样），按结点的值从小到大排序
        dd = sorted(self.d.items(), key=lambda x: (x[1][0], -x[1][1], x[0].val)) # dd类型：list
        res, tmp = [],[]
        pre = dd[0][1][0] # pre 用来判断当前访问的结点和上一个结点是否处在同一根垂直线上
        for item in dd:
            node, pos = item
            if pos[0] == pre:
                tmp.append(node.val)
            else:
                res.append(tmp)
                pre = pos[0]
                tmp = [node.val]
        if tmp: # 最后的 tmp 中可能还有残留，补上！
            res.append(tmp)
        return res
```
