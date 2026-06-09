cn为当前层的节点个数，nn为下一层的节点个数

    def fun(root):
        if not root:
            return 
            
        q = [root]
        ans = []
        nn = 1
        while len(q)>0:
            cn = nn
            nn = 0
            l = []
            for i in range(cn):
                curr = q.pop(0)
                l.append(curr.val)
                if curr.left:
                    q.append(curr.left)
                    nn += 1
                if curr.right:
                    q.append(curr.right)
                    nn += 1
            ans.append(l)

        return ans