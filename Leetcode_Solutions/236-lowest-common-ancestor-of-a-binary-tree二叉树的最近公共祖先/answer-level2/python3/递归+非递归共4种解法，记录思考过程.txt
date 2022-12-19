### 直观思路
首先最直观的思路是DFS搜到p和q，记录下根节点到p到q的2条链表，再遍历比较链表即可。
难点是如何边访问节点边更新链表。之前我写过BFS的题解，对应DFS同理。stack的入栈出栈元素可以设为`(节点，链表)`元组，就能顺利访问更新了。但还有更取巧的办法，在TreeNode定义中加一个属性，让这个属性记录父节点指针：
```python
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.dady = None
```
然后就有了如下迭代DFS的解法。其中的DFS迭代模板当然参考的[简洁经典！易懂易记！团灭前中后序遍历的递归+迭代！](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/jian-ji-jing-dian-yi-dong-yi-ji-tuan-mie-qian-zhon/)
### 迭代解法
上述模板中当stack里pop出的元素是int，就是遍历结果，要加入结果表。应用到本例中，若pop出的是int，应该考虑若此int对应的node是p或q，就记下此node的dady属性。所以就把它加工成`(节点值，节点)`元组了。
另外，比较链表部分就是求两个链表的交点问题，之前链表题目中有此方法应用。
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        root.dady=None
        stack,rst = [root],[]
        ## 迭代DFS
        while stack:
            i = stack.pop()           
            if isinstance(i,tuple):
                if i[0] in (p.val,q.val):
                    rst.append(i[1])
                if len(rst)==2:
                    break
            if isinstance(i,precompiled.treenode.TreeNode):
                stack.append((i.val,i))
                if i.left:
                    i.left.dady=i
                    stack.append(i.left)
                if i.right:
                    i.right.dady=i
                    stack.append(i.right)
        ## 比较rst
        p,q = rst
        while p.val!=q.val:
            p = p.dady if p.dady else rst[1]
            q = q.dady if q.dady else rst[0]
        return p
```

### 递归解法--DFS
同理当然有DFS递归解法。
这里比之前更进一步的是，当访问的node等于p，执行`p.dady = n.dady`，最后用指针遍历pq的dady链表就行了。
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ## 递归DFS
        root.dady,p.dady,q.dady = None,None,None
        def check(n):
            if n.val==p.val:
                p.dady = n.dady
            elif n.val==q.val:
                q.dady = n.dady
        def dady(node):
            if node==None:
                return
            if node.left:
                node.left.dady = node
                check(node.left)
            if node.right:
                node.right.dady = node
                check(node.right)
            assert (p.dady and q.dady) is None
            dady(node.left)
            dady(node.right)
        try:
            dady(root)
        except:
            pass
        i,j = p,q
        while i.val!=j.val:
            i = i.dady if i.dady else q
            j = j.dady if j.dady else p
        return i
```
### 抽象思路
再思考一步，对于一个节点node，它的`(node,node.left,node.right)`中有2个在`(p,q)`中，就能判定它是最近祖先。所以从二叉树的叶子节点开始向上走，对每一个节点来执行一个递归函数，返回这个节点的标签，标签表示此节点及其子树有无p或q。这样逐层向上，当某节点及其子节点的标签`node,left,right`中有2个为True，此节点就是最近祖先。当有1个或0个为True，就返回True或False。于是有了如下解法：
### 递归解法--自底向上
此解法由于递归函数的返回值是True或False，所以得预设结果值，让某节点及其子节点的函数结果有2个为True时记下此节点并返回，有点奇怪了。
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':        
        def lca(node):
            n = node in i
            if node==None:
                return n
            else:
                l = lca(node.left)
                r = lca(node.right)
            _sum = n+l+r
            if _sum==2:
                self.rst = node
                assert _sum!=2
            else:
                return _sum
        try:
            lca(root)
        except:
            pass
        return self.rst         
```
### 递归解法--改进
针对上面解法的改进，让函数直接返回某个node，这样就更加规整了：
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode': 
        def lca(node):
            if node is None: ## 节点为空
                return None
            elif node in (p,q): ## 节点非空，但在pq内
                return node
            else: ## 节点非空，不在pq内
                l = lca(node.left)
                r = lca(node.right)
                if l!=None!=r:
                    return node
                if l==None==r:
                    return None
                else:
                    return l or r                
        return lca(root)
```
上面的解法其实就是评论区高赞解法了。再整理一下代码，可以写得很简短。