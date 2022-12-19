### 解题思路
遍历左子树右子树，把每个节点的层数信息和父亲信息放在两个字典里，最后比较字典储存的信息即可

### 代码


class Solution(object):
    def isCousins(self, root, x, y):
        levelDic = {}
        parentDic = {}

        def dfs(root,height):
            if root != None:
                levelDic[root.val] = height
                if(root.left != None):
                    parentDic[root.left.val] = root.val
                    dfs(root.left,height+1)
                if(root.right):
                    parentDic[root.right.val] = root.val
                    dfs(root.right,height+1)
        
        dfs(root,0)
        return (levelDic[x] == levelDic[y]) and (parentDic[x] != parentDic[y])
```