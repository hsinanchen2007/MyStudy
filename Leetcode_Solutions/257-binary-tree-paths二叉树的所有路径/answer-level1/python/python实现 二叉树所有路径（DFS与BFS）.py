*深度优先搜索思路*：
1、当节点为叶子节点时，添加该路径
2、左右节点深度递归搜索
3、当节点为空时返回
```
def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        def findPath(node,route):
            if node == None:
                return
            else:
                route = route + str(node.val)
                if (node.left==None) and (node.right==None):
                    paths.append(route)
                else:
                    route = route + '->'
                    findPath(node.left,route)
                    findPath(node.right,route)
        paths = []
        findPath(root,'')
        return paths
```
 *广度优先搜索*
维护栈，以先进先出的原则，进行层次搜索，当节点为叶子节点时，添加该路径
```
def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        paths = []
        if root==None:
            return 
        stacks = [(root,str(root.val))]
        while len(stacks)>0:
            root,route = stacks.pop()
            # route = [str(val)]
            if (root.left==None) and (root.right==None):
                paths.append(route)
            if root.left!=None:
                stacks.append((root.left,route+'->'+ str(root.left.val)))
            if root.right!=None:
                stacks.append((root.right,route+'->'+ str(root.right.val)))
            # print(route)

        return paths
```

     


    