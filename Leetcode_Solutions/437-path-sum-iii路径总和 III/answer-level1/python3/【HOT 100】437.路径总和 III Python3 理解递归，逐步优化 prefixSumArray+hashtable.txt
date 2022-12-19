### 补充：
这道题我看着先去看了[560. 和为k的子数组 Subarray Sum Equals K](https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/hot-100-he-wei-kde-zi-shu-zu-python3-cong-bao-li-j/)，然后学到了**prefixSum+HashTable**的优化方式

之前写了半截的暴力解法


### 1.暴力解法
双层递归
核心在于：
**每个node都要计算以它作为起点往下是否有path**  -->  这是一层递归
**在考虑当前点为起点往下有没有path的时候，它的path可以往左也可以往右，于是要综合考虑**  -->  这是另一层递归

那么我们可以写出第一层递归：
```
def pathSum(self, root: TreeNode, sum: int) -> int:
        '''如果没有根节点，整个返回值应该为0，没有路径'''
        if not root:
            return 0
        '''
        self.dfs(root, sum)：这个方法是判断以当前点为起点往下是否有path，也就是path的数量，返回值应该是0或1
        self.pathSum(root.left, sum)：对于左节点我依然要考虑以它为起点往下判断
        self.pathSum(root.right, sum)：同上，于是，此时的sum是不变化的，仍然为初始值
        '''
        return self.dfs(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum)
```

那么对于计算当前点往下是否有`path`，就需要每一步`update`路径的和，题目是希望找到是否有路径总和为`sum`，那么为了简便，可以每一次都减去当前`node.val`，当遇到`path==0`的时候，就说明找到了一条路径，返回1，否则当`root==None`的时候，说明一直找不到路径，返回0

```
def dfs(self, root, path):
        if not root:
            return 0
        '''每一次都要减去当前层的节点值'''
        path -= root.val
        '''
        (1 if path==0 else 0)：说明找到了路径
        self.dfs(root.left, path) self.dfs(root.right, path)：
          此时path更新过，这是因为当前点既可以往左走找path，也可以往右走，是或的关系，只要有一边找到了路径，最终结果都会为1
        '''
        return (1 if path==0 else 0) + self.dfs(root.left, path) + self.dfs(root.right, path)
```

于是整体就能写出代码，一定要理解两个方法递归调用左孩子和右孩子的含义上的区别：

```
class Solution:
    
    def pathSum(self, root: TreeNode, sum: int) -> int:
        
        if not root:
            return 0
        return self.dfs(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum)
        
    def dfs(self, root, path):
        if not root:
            return 0
        path -= root.val
        return (1 if path==0 else 0) + self.dfs(root.left, path) + self.dfs(root.right, path)
```



### 注意：但是这样的效率很低，因为递归层数过深，需要优化：


```
1.遇到subArray就考虑prefixSum和prefixSumArray，用hashtable
2.数组、链表考虑迭代遍历
3.树可左可右的就用递归代替迭代，并且递归结束之后要删掉当前层的tmp value
  递归理解调用栈
  并且：由于是递归而不是迭代，需要新的一个函数，且需要将prefixSum和prefixSumArray当作参数传入进去
```

### 2.prefixSum和prefixSumArray，+hashtable

类似[560. 和为k的子数组 Subarray Sum Equals K](https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/hot-100-he-wei-kde-zi-shu-zu-python3-cong-bao-li-j/)，可以每次求出累加和，然后找到累加和和`sum`的差值，也就是距离为`sum`的路径，判断差值是否在我们用来保存每一个`prefixSum`的`hashtable`里，也类似`2sum`问题

![image.png](https://pic.leetcode-cn.com/f10fbdfb22e3726e3a2a15a014ad653b9bc2ffcfbce9365777b030fd0568b921-image.png)


```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        prefixSumTree = {0:1}
        self.count = 0
        
        prefixSum = 0
        self.dfs(root, sum, prefixSum, prefixSumTree)
        
        return self.count
        
        
    def dfs(self, root, sum, prefixSum, prefixSumTree):
        if not root:
            return 0
        prefixSum += root.val
        oldSum = prefixSum - sum
        if oldSum in prefixSumTree:
            self.count += prefixSumTree[oldSum]
        prefixSumTree[prefixSum] = prefixSumTree.get(prefixSum, 0) + 1
        
        self.dfs(root.left, sum, prefixSum, prefixSumTree)
        self.dfs(root.right, sum, prefixSum, prefixSumTree)
        
        '''一定要注意在递归回到上一层的时候要把当前层的prefixSum的个数-1，类似回溯，要把条件重置'''
        prefixSumTree[prefixSum] -= 1
```


### 3.日常反思

推荐一本书：《被讨厌的勇气》，能够让我看自己看得更清楚，知道之后，重要的要去迈出那一步要去改变。