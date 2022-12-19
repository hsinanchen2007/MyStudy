```
class treeNode:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val
        self.count = 0

class Solution:
    def countSmaller(self, nums):
        len_nums = len(nums)
        if len_nums == 0:
            return []

        root = treeNode(nums[len_nums-1])
        res = [0 for _ in range(len_nums)]        
        for i in reversed(range(0,len_nums-1)):
            newNode = treeNode(nums[i])
            node = root
            while True:
                if newNode.val > node.val:
                    res[i] += node.count + 1
                    if node.right != None:
                        node = node.right
                    else:
                        node.right = newNode
                        break
                else:
                    node.count += 1
                    if node.left != None:
                        node = node.left                            
                    else:
                        node.left = newNode                          
                        break
       
        return res
```
