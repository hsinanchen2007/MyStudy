可以分为三步来处理：
**（1）计算树的高度（通过一个简单的递归函数）**
树的高度决定了填充数组的列数和行数：
columns = 2**height - 1
rows = height
**（2）构造一个二维空数组**
python中可以用链式表达式一行实现：
array = [[""]*columns for _ in range(rows)]
**（3）DFS遍历二叉树**
要点：
注意递归边界：当前结点为空，或者开始填充的位置大于结束的位置
传入填充的开始结束位置，方便确定填充范围和定位中点
对于每一层/行，先渲染中点的位置（用当前结点的值填充即可），然后分别分割左、右两部分，进行递归填充
**详见代码注释部分**
```
class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        if not root:
            return []
        # 1.计算高度
        def countHeight(root):
            if not root:
                return 0
            return max(countHeight(root.left), countHeight(root.right)) + 1
        height = countHeight(root)
        print("height:", height)
        columns = 2**height - 1 # 列数/列的最大长度
        rows = height # 行数
        # 2.构建数组
        array = [[""]*columns for _ in range(rows)]
        # 3.dfs 二分填充数组（从中间即root位置分割开，分别往左、往右递归填充）
        def dfsPaint(node, array, row, start, end):
            if not node or start > end:
                return
            if start == end:
                array[row][start] = str(node.val)
            else:
                # 渲染当前结点，在树的中间位置
                middle = start + (end - start) // 2
                array[row][middle] = str(node.val)
                # 左子树渲染
                dfsPaint( node.left, array, row + 1, start, middle - 1)
                # 右子树渲染
                dfsPaint(node.right, array, row + 1, middle + 1, end)
        dfsPaint(root, array, 0, 0, columns-1)
        print("array:", array)
        return array
```

