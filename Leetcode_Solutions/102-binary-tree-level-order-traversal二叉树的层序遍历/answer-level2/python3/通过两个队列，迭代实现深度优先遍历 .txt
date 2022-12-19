```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        #两个队列
        prequeue = [root]
        queue = []
        #两个list分别用来记录prequeue得到的list和最终的返回值
        preres= []
        res = []        
        while prequeue :            
            curr = prequeue.pop(0)
            #对prequeue队列进行遍历并同时得到下一个队列
            if curr != None:
                queue.extend([curr.left,curr.right])
                preres.append(curr.val)
            #prequeue队列搜索完毕，则更新结果，并更新prequeue
            if prequeue == []:
                if preres !=  []:
                    res.append(preres)
                prequeue = queue
                queue = []
                preres = []
        return res
            
```
