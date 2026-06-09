### 更新：整理思路

合并两个二叉树，那么`让一棵树累加到另一棵树`是更为简单的方式：
那么我们以`tree1`为基准，将`tree2`覆盖累加，于是应该使用`递归`的方式进行遍历，但是那如何递归呢？

```
if root1，那么才应该递归下去，保证当前节点有内容，
但如果root1没有，root2有呢，所以应该是更新父节点，递归子节点的模式进行递归，
并且需要在两棵树的父节点都存在的时候，才去递归子节点
```

那么更父节点就是累加当前的节点值到基准树上：
```
t1.val += t2.val
```

那又如何递归子节点呢？一种**常用的方式**就是：
```
root.left = self.fun(root.left)
root.right = self.fun(root.right)
```
这样的话就要求调用的函数返回的是一个node，那么我们就可以写出不同的情况下函数的返回值了：
```
# 可以省略，会进入下面的if，返回另一个为空的节点
# if not t1 and not t2:  
#    return
if not t1:
    return t2
if not t2:
    return t1

# else情况，更新root，并递归更新，返回一个合并节点
t1.val += t2.val
... # 递归更新子节点
return t1
```

更新子节点就需要同步传入两棵树的当前节点的左右子树：
```
t1.left = self.mergeTrees(t1.left, t2.left)
t2.right = self.mergeTrees(t1.right, t2.right)
```


于是就可以写出完整的简洁的代码了：
```
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 and not t2:
            return 
        if not t1:
            return t2
        if not t2:
            return t1
        
        t1.val += t2.val
        
        t1.left = self.mergeTrees(t1.left, t2.left)
        t1.right = self.mergeTrees(t1.right, t2.right)
        
        return t1
```






###  > 分割线--------------------------以下原文


拿到这个题的第一反应是递归的去累加，然后构建一个新的树，但是由于思路的不清晰，思考了二年都没有想出来怎么做，

第一个错误的是，每次都去递归的getNext直到我找到最左的左节点，然后进行一个merge，也就是我想从下往上的递归，但是问题是我可能一个树有很多个左节点，另外一个树我可能没有左节点，反正整个思路都不清晰，甚至加了flag这种神奇的东西来进行判断

其实主要当时想的合并两个链表，但是链表好考虑啊，就只有一个next属性，但是树就不一样了，要考虑left和right是否存在。。。
反正就是这个我自己都讲不出思路，但是我感觉我还是应该**自上而下**的递归：

![image.png](https://pic.leetcode-cn.com/f3f00284160f82529ed94cdfedbe48d66cc016922ca3568fcf7a002606011d0d-image.png)

### 1.错误1：

```
class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        tmp = t1
        
        left1 = self.getNext(t1.left, 'left')
        left2 = self.getNext(t2.left, 'left')
        
        right1 = self.getNext(t1.right, 'right')
        right2 = self.getNext(t2.right, 'right')
        
        t1.left = self.merge(left1, left2, 'left')
        t1.right = self.merge(right1, right2, 'right')
        
        return tmp
    
    def getNext(self, head, flag):
        if flag == 'left':
            if not head.left:
                return head
            self.getNext(head.left, flag)
        else:
            if not head.right:
                return head
            head = self.getNext(head.right, flag)
            
    def merge(self, p, q, flag):
        if flag == 'left':
            
            if p and q:
                return TreeNode(p.val+q.val)
            if p:
                return p
            if q:
                return q
            return None
            
        if flag == 'right':
            
            if p and q:
                return TreeNode(p.val+q.val)
            if p:
                return p
            if q:
                return q
            return None
```



### 2.错误2：


然后我就**自上而下**吧，但是这一次就很多if堆砌，然后跑过了样例数据，然后我就骄傲了，选择了提交，然后当然是很显然的**解答错误**
一看错误样例，卡在了这种树上：
![image.png](https://pic.leetcode-cn.com/b96af8cc0b2f96a660f96038630228665dd9c624753dc5ccb0f5e7a2eb3d3896-image.png)

原因在于，算了我已经不记得我的原因是什么，但是还是乱得很的思路。。。
这种简直是**烂代码**

```
class Solution(object):
    def mergeTrees(self, t1, t2):

        res = None

        if t1 and t2:
            res = TreeNode(t1.val + t2.val)
        elif t1:
            return t1
        elif t2:
            return t2
        else:
            return None

        tmp = res

        self.merge(tmp, t1, t2)

        return res

    def merge(self, root, t1, t2):
        if not t1 and not t2:
            return

        if t1 and not t2:
            return t1
        if t2 and not t1:
            return t2

        if t1.left and t2.left:
            root.left = TreeNode(t1.left.val + t2.left.val)
        elif t1.left:
            root.left = TreeNode(t1.left.val)
        elif t2.left:
            root.left = TreeNode(t2.left.val)
        else:
            root.left = None

        if t1.right and t2.right:
            root.right = TreeNode(t1.right.val + t2.right.val)
        elif t1.right:
            root.right = TreeNode(t1.right.val)
        elif t2.right:
            root.right = TreeNode(t2.right.val)
        else:
            root.right = None

        if root.left:
            self.merge(root.left, t1.left, t2.left)

        if root.right:
            self.merge(root.right, t1.right, t2.right)
```

### 3.终于对了：

然后我在今天的早上重新画了图，思考了一下我的最新思路：（再做不出来我要怀疑人生了。。）

- 我需要新建一棵树来作为我的结果，并采用递归的方式是自上而下的获取左右子节点 
- 那么我首先需要合并两棵树的root，用一个merge_方法，这个merge_方法传入的参数为`merge_(t1, t2)`，返回的值为一个新的TreeNode
- 然后递归的调用一个获取子节点的merge方法，这个merge方法传入的参数为`merge(res, t1, t2)`，res为返回的合并节点，并且不是合并当前节点，是用`res.left=merge_(t1.left, t2.left)和res.right=merge_(t1.right, t2.right)`来考虑下层子节点
- 在这个merge函数中，我需要首先判断t1和t2是否存在，如果都不存在则返回，如果其中一个不存在，则直接将存在的left和right子树赋给res的left和right部分，只有当t1和t2都存在的时候，才会累加，并且继续递归 


```
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:

        res = self.merge_(t1, t2)
        tmp = res
        self.merge(tmp, t1, t2)
        
        return res
        
    def merge(self, res, t1, t2):
        if not t1 and not t2:
            return res
        if not t1:
            # res.left = t2.left
            # res.right = t2.right
            res = t2
        elif not t2:
            # res.left = t1.left
            # res.right = t1.right
            res = t1
        else:
            res.left = self.merge_(t1.left, t2.left)
            res.right = self.merge_(t1.right, t2.right)
            self.merge(res.left, t1.left, t2.left)
            self.merge(res.right, t1.right, t2.right)
        
    def merge_(self, t1, t2):
        if t1 and t2:
            return TreeNode(t1.val+t2.val)
        if t1:
            return TreeNode(t1.val)
        if t2:
            return TreeNode(t2.val)
        return None
```

![image.png](https://pic.leetcode-cn.com/6103414f71bd94157db71ab1286863a2edd943c44fe39bc80a28696dc0a1362d-image.png)


### 新思路：

还是复杂的弱鸡思路，看了一眼别人的代码，短小精干的让我哭泣。。。
原来还可以这样：**递归的把t2这棵树累加到t1这棵树上，然后返回t1**，直接不用构造新的树了，直接简单明了的合并两棵树。。。
原来思路是多么的重要。。（自我安慰是因为我写的太少了没有下意识的经验叭。。）

```
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        
        if not t1 and not t2:
            return

        if not t2:
            return t1
        
        if not t1:
            return t2
         
        else:
            t1.val = t1.val + t2.val
            '''还是用t1.left = 递归，t1.right = 递归的方式，那么原方法就需要返回一个TreeNode，也就是base case'''
            t1.left = self.mergeTrees(t1.left, t2.left)
            t1.right = self.mergeTrees(t1.right, t2.right)
        
        return t1
```



![image.png](https://pic.leetcode-cn.com/24820bd9e5923180fa53cde672029138760552f951692e29efd5026c8ed94182-image.png)


【那么，还是请小菜鸡多写题吧！！】