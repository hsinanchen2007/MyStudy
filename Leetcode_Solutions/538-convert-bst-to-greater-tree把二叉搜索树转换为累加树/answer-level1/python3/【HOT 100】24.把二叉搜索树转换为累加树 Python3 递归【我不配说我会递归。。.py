
### 1.递归，理解递归
我知道要用递归，而且我的树的题都会开场一句“我看到这道题就是想到递归”
但是这道题我败了。。。这是道简单题啊喂！

先去偷了人家一个画图：灵魂画手画不动这么长的图了。。。

![image.png](https://pic.leetcode-cn.com/158b849fb71a0a0865beb960f4d0bdec27ba85d64003ab96dbfac14bbd5d6dd1-image.png)

很明显是要右根左的遍历，那先写一个右根左的遍历打印看看：
```
class Solution:
    def traversal(self, root):
        if not root:
            return

        self.traversal(root.right)
        print(root.val)
        self.traversal(root.left)

```

然后我在按**右根左**的顺序遍历了二叉搜索树之后，我希望我每一次都带上前一次的累加结果，那么我传入这个traversal的方法肯定要带上这样的一个参数：`self.traversal(root, pre_sum)`
那么我这个函数内部应该怎么修改呢？遍历顺序肯定不变，但是这个函数的返回值应该需要变化，如果没有root，我应该返回什么呢，其实我应该返回的是`pre_sum`这个值，因为我之前的累加值，然后当前没有节点了，就应该把我一直保存的累加值返回回去
那么既然我这个函数有返回值，那么我每一次遍历右子树，都应该获得这个结果，并每次都更新我的`pre_sum`，这样用于之后的累加更新：`pre_sum = self.traversal(root.right, pre_sum)`，那么在遍历根节点的时候我每次应该如何进行修改呢，我应该是把之前的累加值和我当前的节点的值进行相加，这样达到累加树的效果：`root.val += pre_sum`，然后之后我应该怎么去递归左子树呢，我传入的pre_sum还应该是之前的pre_sum吗？
递归左子树`root.left`的时候，累加值是传入的累加值`pre_sum`和根节点的原值`root.val`的合，其实在更新`root.val += pre_sum`的时候就已经累加了`pre_sum`，所以这时传入`root.val`就可以了：`pre_sum = self.traversal(root.left, root.val)`
这样就完成了从右根左遍历到累加树的改变：

```
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        
        if not root:
            return
        
        self.traversal(root, 0)
        
        return root
    
    def traversal(self, root, pre_sum):
        if not root:
            return pre_sum
        
        pre_sum = self.traversal(root.right, pre_sum)
        root.val += pre_sum
        pre_sum = self.traversal(root.left, root.val)
        
        return pre_sum
```

但是我对递归的理解还是不够深入，最初的代码是这样：
### 2.错误
```

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        
        if not root:
            return
        
        self.traversal(root, 0)
        
        return root
    
    def traversal(self, root, pre_sum):
        if not root:
            return pre_sum
        
        pre_sum = self.traversal(root.right, pre_sum)
        root.val += pre_sum
        self.traversal(root.left, root.val)
        
        return root.val
```

这样并没有更新到pre_sum，反正传给4的时候，还是用了6+7的pre_sum而没有带上5，应该是递归left的时候的影响
这一棵树：
```              
           4
         /   \
       2       6
     /   \   /   \
    1     3 5     7
```

一定要多理解递归，多做做相关的题！！！