给树中的每一个节点进行编码，根节点为0，然后如果是左节点，值为根节点的二倍；如果是右节点，值为根节点的二倍加一，这样编出来的码就如图所示。
![QQ截图20190815173647.png](https://pic.leetcode-cn.com/e9d7208a8bdc787df3c5856d1d6d14a5bd4075ef211596e06c12103281b154a1-QQ%E6%88%AA%E5%9B%BE20190815173647.png)
再将每一层对应的编码放入一个hash表，求出每一层节点中编码的最大差值即为答案

```python []
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if root==None:  #特殊判定
            return 0
        res=0
        temp={} #定义一个temp来记录树中每一层对应的编号
        def core(a,k,j):
            if k not in temp: 
                temp[k]=[]
            temp[k].append(j)  #将每一层对应的编号放进hash表
            if a.left:
                core(a.left,k+1,j*2) #编码规则，左节点为当前值的二倍
            if a.right:
                core(a.right,k+1,j*2+1)#编码规则，右节点为当前值的二倍加一
        core(root,0,0) #调用core函数
        for x in temp: #找到每一层中的编号最大差值，即为所求
            res=max(res,temp[x][len(temp[x])-1]-temp[x][0]+1)
        return res
```