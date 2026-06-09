整体思想：
（1）将每个节点的父结点，每个节点的层数和每个节点的索引放进队列中；
（2）在遍历队列的时候，构建每个节点的字典，将每个节点的值作为key，每个节点的父结点和所在层所作为value；
（3）得到所有数据的字典信息，查询X和Y的信息是否匹配，输出最后的结果；
（4）为了节省时间，当查询到x和y之后，就结束队列遍历；


```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if not root:
            return False

        dicts = {}   # 用于保存每个节点的信息（每个节点所在的层数和父结点）
        queue = collections.deque()   # 创建一个队列
        queue.append([root,None,1])   # 将根节点放进队列中
        flag_x = False   # 用于标记是否已经遍历到x
        flag_y = False   # 用于标记是否已经遍历到y
        while queue:
            roots,froot,d = queue.popleft();  # 获得当前节点的父结点，当前节点的层数
            dicts[roots.val] = [froot,d]   # 将当前节点的信息放到字典中

            if roots.val == x:  # 如果x和y已经被搜索到，就结束队列遍历
                flag_x = True
            if roots.val == y:
                flag_y = True
            if flag_x and flag_y:
                break

            if roots.left:    # 如果左子节点不为空，则将左子节点的信息作为一个列表放进队列中
                queue.append([roots.left,roots,d+1])
            if roots.right:   # 如果右子节点不为空，则将右子节点的信息作为一个列表放进队列中
                queue.append([roots.right,roots,d+1])

        if dicts[x][0]!=dicts[y][0] and dicts[x][1]==dicts[y][1]:  # 查询字典中x和y的信息是否匹配
            return True
        return False
```
时间复杂度应该是O(n)，空间复杂度是O(n)。