### 解题思路
此处撰写解题思路
注意事项：
1 二叉搜索树，符合 left<val<right
2 遍历所有根节点，小值送入左树，大值送入右数
3 截止条件，n为0时返回[],而非返回[[None]]

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n <= 0 :return []
        nums = range(1,n+1)
        return self.generateSubTree(nums)
        #返回
    def generateSubTree(self,num_list):
        ret = []
        if not num_list:return [None]
        for index in range(len(num_list)):
            
            #返回左子树所有可能list
            left_list = self.generateSubTree(num_list[:index])
            #返回右子树所有可能list
            right_list = self.generateSubTree(num_list[index+1:])
            #拼接左右
            for i in left_list:
                for j in right_list:
                    node = TreeNode(num_list[index])
                    node.left = i
                    node.right = j
                    ret.append(node)
        
        return ret



```