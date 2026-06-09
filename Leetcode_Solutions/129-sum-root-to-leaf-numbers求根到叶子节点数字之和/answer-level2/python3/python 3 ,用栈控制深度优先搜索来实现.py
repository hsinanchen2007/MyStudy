先做简单的题目，类似的，而后来到这里，需要注意的是，

#[:] the point ,my mistake 
代码中的这里，需要注意，我当时的错误，
第一步，通过栈，控制递归，得到所有路径的嵌套list ，也就是 res
第二步，再来处理 第一步得到的嵌套list ，也就是所有的路径。

这个题，是多维度的问题，一个维度一个维度的处理。

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        stack = []  #use stack to control the traverse
        
        sum333=[]  #temp list for every path 
        
        res=[]  # res maybe = [[1,2],[1,3]]
        
        def dfs(root,stack,sum333):  #dfs 3 arguments
        
            if not root :
                return   
                
            stack.append(root)
            
            while stack:
        
                nn=stack.pop()
                sum333.append(nn.val)
                
        
                if nn.left is None and nn.right is None:
                    #print(sum333)
                    res.append(sum333)
                else:
                    dfs(nn.left,stack,sum333[:])    #[:] the point ,my mistake 
                    dfs(nn.right,stack,sum333[:]) 
                    
            return res
        
        res2 = dfs(root,stack,sum333) 
        
        #step two , get the sum of the list--->haha
        haha=0
        if res2 is None:
            haha=0
        else:
            ttt2=[]
            for i in res2:
                #print(i)
                kk=len(i)  #kk=3
                ss=0
                for j in i:
            
                    ss=ss*10 +j
                ttt2.append(ss)
                    
            haha=sum(ttt2)
        
        return haha