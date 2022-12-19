- 先是迭代
- 执行用时 : 32 ms , 在所有 Python3 提交中击败了 76.51% 的用户
  内存消耗 : 13 MB , 在所有 Python3 提交中击败了 50.41% 的用户
```
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        stack = [root] # 用来装 所有值为root.val的结点及直接子结点
        minimumValue = root.val
        res = [] # 用来装 所有大于root.val的直接子结点 的值
        
        while stack:
            node = stack.pop()
            if node.left and node.right:
                if node.left.val == minimumValue:
                    stack.append(node.left)
                else:
                    res.append(node.left.val)
                    
                if node.right.val == minimumValue:
                    stack.append(node.right)
                else:
                    res.append(node.right.val)
        return min(res) if res else -1
```
- 时间复杂度：(O(x)):循环是主要的时间花费，这里一共进行了x次循环，x指所有值为root.val的结点及直接子结点。至多是全部结点，至少是根结点
- 空间复杂度：(O(x+y)):stack和res是额外存储，res用来装所有大于root.val的直接子结点的值，一共有y个值。至多是所有叶结点，至少是空
- （当然可以只用一个变量，表示大于root.val的直接子结点中的最小值，只需在循环过程中，随时更新最小值）





- 再来看递归
- 执行用时 : 28 ms , 在所有 Python3 提交中击败了 89.84% 的用户
  内存消耗 : 12.7 MB , 在所有 Python3 提交中击败了 74.59% 的用户
 ```
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        secondMinimumValue, minimumValue = float('inf'), root.val
        def find(node):
            if node:
                nonlocal secondMinimumValue, minimumValue # 指明这两个变量(secondMinimumValue, minimumValue) 是封装在 临近的 外层函数(find)中的 局部变量
                if node.val < secondMinimumValue and node.val != minimumValue: # 递归找到所有结点中 值不是root.val的最小值
                    secondMinimumValue = node.val
                find(node.left)
                find(node.right)

        find(root)
        return secondMinimumValue if secondMinimumValue != float('inf') else -1 # 如果secondMinimumValue还是初始最大值 那说明不存在要找的数 返回-1
```
- 时间复杂度：(O(n)):循环n次
- 空间复杂度：(O(n)):分配递归栈n次






- **总结：**
平均情况下，时间空间复杂度都是迭代更优（我跑出来结果相反，你萌的结果呢）