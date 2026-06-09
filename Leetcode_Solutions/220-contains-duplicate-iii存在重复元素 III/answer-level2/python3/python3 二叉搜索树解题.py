### 关键思路
- 首先`i,j`间距最大为k，就是长度k的滑动窗口了。
- 要求时间复杂度O(nlogk),显然要将这长度为k的窗口的数据用在二叉树上面。
- 用窗口数据建立二叉搜索树，随着窗口滑动，删除节点并增加节点。
- 增加节点时判断待增加值是否和现有二叉搜索树的值有距离<=t的，
- 有直接返回True，否则继续滑动窗口直到结束返回False。
### 代码实现
由于测试案例中有10000长度的窗口，需要构建平衡树否则树这里最坏会退化到O(n)。加一个触发条件来平衡，平衡方法是先中序遍历现有树得到`list`,再将此`list`变为平衡二叉树。
```python
class Node:
    def __init__(self,v):
        self.val = v
        self.left = None
        self.right = None

class Solution:
    def delete(self,node,val):
        if node.val==val:
            if None in [node.left,node.right]:
                return node.left or node.right
            else:
                ii = node.left
                while ii and ii.right:
                    ii = ii.right
                ii.right = node.right
                return node.left
        elif node.val>val:
            node.left = self.delete(node.left,val)
        elif node.val<val:
            node.right = self.delete(node.right,val)
        return node
        
    def add(self,node,val):
        if node==None:
            return Node(val)
        assert abs(node.val-val)>self.t
        if node.val<val:
            node.right = self.add(node.right,val)
        if node.val>val:
            node.left = self.add(node.left,val)
        return node            

    def inorder(self,node):
        if node:
            self.inorder(node.left)
            self.list.append(node.val)
            self.inorder(node.right)
            
    def balance(self,_list):
        l=len(_list)
        if l:
            node = Node(_list.pop(l//2))
            node.left = self.balance(_list[:l//2])
            node.right = self.balance(_list[l//2:])
            return node
    
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        tree = None                
        self.t = t
        for i,v in enumerate(nums):            
            ## 删除节点
            if i>k:
                tree = self.delete(tree,nums[i-k-1])            
            ## 加入i节点
            try:tree = self.add(tree,v)
            except:return True
            ## 平衡树
            if i%5000==0: ## 这里参数可调，自测3000~5000均可
                self.list=[]
                self.inorder(tree)
                tree = self.balance(self.list)               
        return False
```
### 复杂度分析
时间：最佳O(nlogk),最差O(nk) ## 毕竟没真正实现平衡二叉搜索树。但红黑树啥的还没学呢！
空间：O(n)
执行用时 :328 ms, 在所有 Python3 提交中击败了6.69%的用户
内存消耗 :17.3 MB, 在所有 Python3 提交中击败了6.31%的用户