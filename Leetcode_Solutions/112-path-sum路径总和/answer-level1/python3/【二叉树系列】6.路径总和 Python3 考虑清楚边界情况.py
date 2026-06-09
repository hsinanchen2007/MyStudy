
### 0.叨叨
今天把罗里吧嗦的放在前面我要激励我自己！！
懒散了好多天，当然也有一些生活工作上的变化，我终于来了北京。。。
但是前一段时间的非紧张工作状态让我最近都很难投入新的工作和学习，常常混迹王者大峡谷，连写题都不写了，题解更是更懒了。
慢慢悠悠的今天又看起来力扣，结果一条评论让我感动万分。。
![image.png](https://pic.leetcode-cn.com/b755bb18511da2af171e6341d37608a0ad4f01b79c7f612fc8a5ba6141f289c7-image.png)
没想到我的题解能够获得这样的回复！（当然其他人的评论也让我开心不已！！）
感谢来得很难得，所以我决定一定要坚持下去，不能因为主观原因而停滞！
一定要加油，周围很多大佬，动不动清北，我小菜鸡真的很想哭，一定要在新环境让自己蜕变！

心之所向，来到了想到的地方，就不能辜负这一切。



### 1.正题

这道题是我的过渡题，从懒散回到学习工作状态的一道题，太久没有写题确实脑子已经不能太够用，只能想到递归累加，在最终遇到叶子节点的时候去判断是否和`target sum`相等

```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        return self.check(root, 0, sum)
        
        
    def check(self, root, pre, sum):
        # if not root:
        #     if pre == sum:
        #         return True
        #     return False
        if not root.left and not root.right:
            if pre+root.val == sum:
                return True
            return False
        l = False
        r = False
        
        if root.left:
            l = self.check(root.left, pre+root.val, sum) 
        if root.right:    
            r = self.check(root.right, pre+root.val, sum)
            
        return l or r
```


![image.png](https://pic.leetcode-cn.com/9f84d9cbf5cacec46cfbbe40dc27c62755933610de7c7c916e6bb01359dc9268-image.png)

其实我最开始的问题在于对于`check`函数的边界问题没有考虑清楚，在`if not root`的时候，应该直接返回`False`而不是再去判断，这样就不需要在调用`check`函数的时候先判断是否有左右孩子了：

```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        return self.check(root, 0, sum)
        
        
    def check(self, root, pre, sum):
        if not root:
            return False
        if not root.left and not root.right:
            if pre+root.val == sum:
                return True
            return False
        
        return self.check(root.left, pre+root.val, sum)  or self.check(root.right, pre+root.val, sum)
```


然后想到，我累加的每一步，我能不能用sum去减去每次经过的节点的值，这样在遇到叶子节点的时候可以通过`sum ?= 0`来判断是否为正确答案，这样的优势在于不需要单独再写一个函数来传入pre的累加值，而在当前函数内就可以用sum进行相关操作：

```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        sum -= root.val
        if not root.left and not root.right:
            return sum == 0
        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)
```

不过。。运行时间一次比一次长。。。无力解答。。快快恢复健康身体和好的学习状态吧！！plz

