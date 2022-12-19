思路：  
    - 空节点当作树的叶子节点。  
    - 树的特征：当遍历完整棵二叉树时，叶子节点的数目总是比非叶子节点的数目多1。  
    - 从数组开头遍历，在遍历的过程中判断应保证非叶子节点的数目countNode不小于叶子节点的数目countNone。  
    - 当遍历到最后一个位置时，需要保证最后一个元素为空，否则，该数组不可能是一个二叉树的前序序列化。  
    - 另外，叶节点的数目不可能小于2。
```
class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        preorder = preorder.split(",")
        
        countNone, countNode = 0, 0
        for i in range(len(preorder)-1):
            if preorder[i] == "#":
                countNone += 1
            else:
                countNode += 1
            if countNode >= countNone:
                continue
            else: 
                return False
            
        # 将空看作叶节点，不可能存在少于1个叶节点的树结构。   
        # 另外，若该数组是一个二叉树序列，则当遍历到倒数第二个节点时，叶节点和非叶子节点的数目一定相同。
        if countNone != countNode:
            return False
        else:
            return True if preorder[-1] == "#" else False
        
```
