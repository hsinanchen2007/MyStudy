### 解题思路
做完深度又做这道题，想当然的先获取深度再根据深度构建结果数组，然后递归填充数据
应该有更好办法，树遍历了两次

### 代码

```python
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        #先获取深度
        if root is None:return []
        else:
            maxDepth=self.maxDepth(root)
            resultList=[]
            for i in range(maxDepth):
                resultList.append([])
            resultList[maxDepth-1].append(root.val)
            self.solr(maxDepth-2,root.left,root.right,resultList)
            return resultList
            #开始遍历
    def solr(self,depth,left,right,resultList):
        if left is not None:
            resultList[depth].append(left.val)
            self.solr(depth-1,left.left,left.right,resultList)
        if right is not None:
            resultList[depth].append(right.val)
            self.solr(depth-1,right.left,right.right,resultList)
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None: return 0
        else: return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
```