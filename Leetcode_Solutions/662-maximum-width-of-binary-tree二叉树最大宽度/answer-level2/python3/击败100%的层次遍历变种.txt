
![搜狗截图20年01月29日2353_1.png](https://pic.leetcode-cn.com/4a0856e6f2a4215933e6e26bc08ea1c554254400b4bbf9f6495bb2969a7bc9ef-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B401%E6%9C%8829%E6%97%A52353_1.png)

# 主要思想：（索引从0开始）
**假设父节点在n层的索引为x，则其左子节点在层n+1的索引为2x,其右子节点在层n+1的索引为2x+1**
# 操作步骤：（基于层级遍历）
在遍历时，不再将节点的值存入结果，而是存该节点的索引值！
```
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:return 0
        order=[]
        #层次遍历（depth为深度，index为节点在节点所在层的索引）
        def main(depth,root,index):
            if not root:return 
            try:
                order[depth].append(index)
            except:
                order.append([index])
            main(depth+1,root.left,2*index)
            main(depth+1,root.right,2*index+1)
            return
        main(0,root,0)
        max_width=0
        for i in order:
            max_width=max(max_width,i[-1]-i[0]+1)
        return max_width
```
