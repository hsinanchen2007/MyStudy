![搜狗截图20年01月30日1438_1.png](https://pic.leetcode-cn.com/783714ddc58be01c16ec460bbea66f463d03d02275df73bf2695f64113153664-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B401%E6%9C%8830%E6%97%A51438_1.png)
# 辅助工具：
1.题目102：二叉树的最大深度
2.题目662：二叉树的最大宽度
# 主要思路：
1.所求结果矩阵的m,n（行、列）：可根据数学归纳法得出以下结论
（1）m=二叉树的最大深度max_depth(根节点为第1层)
（2）n=2的m次方-1
2.已知节点在本层的索引i（题目662：二叉树的最大宽度），如何求得在矩阵中的列索引i_new：根据公式推导得出以下结论
i_new=((n+1)/(2**(d+1)))*(2*i+1)-1
其中d，i是该节点在层次遍历时的所在层数（根节点为第0层）、所在层数的索引（最左侧为第0个）
***证明：***
已知矩阵的列数为n，则该节点所在层数d最多有2^d个节点，每个节点占据
x=(n+1)/(2^d)个位置，该节点占据的范围的第一个位置索引为
i*x处，节点应在该范围的中心，即应该在i×x后的△=(n+1)/(2^(d+1)-1处
即i_new=i×x+△，换算后得到所证公式
# 操作步骤：
1.求树的最大深度
2.层次遍历中存储节点[层数d，值v，索引i]信息到order列表
3.将order列表中的节点按照公式修改res，输出即可
```
class Solution:
    def maxDepth(self, root):
        if root is None: return 0 
        else: 
            left_height = self.maxDepth(root.left) 
            right_height = self.maxDepth(root.right) 
            return max(left_height, right_height) + 1 
    def printTree(self, root: TreeNode) -> List[List[str]]:
        if not root:return [[""]]
        max_depth=self.maxDepth(root)
        m,n=(max_depth),(2**(max_depth)-1)
        res=[[""] * n for i in range(m)]
        #层次遍历（depth为深度，index为节点在节点所在层的索引）
        order=[]#储存存在的节点[深度，值，索引]
        def main(depth,root,index):
            if not root:return 
            order.append([depth,root.val,index])
            main(depth+1,root.left,2*index)
            main(depth+1,root.right,2*index+1)
            return
        main(0,root,0)
        for d,v,i in order:
            i_new=int(((n+1)/(2**(d+1)))*(2*i+1)-1)
            res[d][i_new]=str(v)
        return res
```
