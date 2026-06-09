一般dfs用的比较多的是回溯法，这里针对
‘‘要么取节点左边的一串，要么取节点右边的一串进行分治’’
这一特性
```
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        if not root:
            return ''
        def amas(node,A) ->str :
            if node:
                t=chr(node.val+97)
                A+=t
                if node.right==None and node.left==None:
                    return A[::-1]
                else:
                    return min(amas(node.left,A),amas(node.right,A)) 
            else:
                return '~'  #借鉴上一种方法，~的ASCII码值大
        
        
        return amas(root,'')
            
```


