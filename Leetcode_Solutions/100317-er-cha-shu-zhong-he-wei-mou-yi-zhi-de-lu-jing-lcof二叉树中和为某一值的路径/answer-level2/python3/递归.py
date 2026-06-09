```
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        self.dic = {}
        def search(parent,  root, count):
            if root == None: return 
            count = root.val+count
            self.dic[root] =[parent, count, 0]
            if root.left == root.right == None and count == sum: self.dic[root][2] = 1
            search(root, root.left, count)
            search(root, root.right, count)

        def findParent(root):
            if root == None: return []
            arr = [root.val]
            while self.dic[root][0] != None:
                root = self.dic[root][0]
                arr.append(root.val)
            return arr[::-1]
        ans = []
        search(None, root, 0)
        for key,val in self.dic.items():
            if val[2] ==1:
                ans.append(findParent(key))
        return ans 
```
