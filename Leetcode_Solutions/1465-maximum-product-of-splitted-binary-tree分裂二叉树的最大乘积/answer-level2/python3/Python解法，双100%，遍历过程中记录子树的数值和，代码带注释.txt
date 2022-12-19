# 一、思路

所谓的分裂二叉树，是指把二叉树任意一个子树和其他部分分离开。

也就是说，**求分裂二叉树的乘积，本质是求任意子树的数值和，和二叉树剩余部分的数值和的乘积**。

为此，我们需要：

**1. 各个子树的数值和**

**2. 二叉树的数值总和**

一般而言，求二叉树数值和可以采用从下至上的过程。为求二叉树有的数值总和，我们可以先分别求左子树、右子树的数值和，再将他们和根节点的值相加。

在这过程中，**我们已经获取了二叉树的子树和，因此只需要记录下来，不需要再次遍历。**

**为了减少重复数值对计算的影响，我们利用集合set记录子树和。**

# 二、代码及注释

```
class Solution:
    arr = set()                            # 全局变量，集合arr

    def calculateSum(self,root):           # 计算每一层的sum值
        if not root:                       # 非节点，返回0
            return 0
                                           # 计算该节点值与左子树和右子树对应sum的总和
        res = root.val + self.calculateSum(root.left) + self.calculateSum(root.right)
        
        self.arr.add(res)                  # 将sum加入集合

        return res                         # 返回sum

    def maxProduct(self, root: TreeNode) -> int:
        self.arr = set()                   # 初始化arr
        node_sum = self.calculateSum(root) # 计算总和
        res = 0

        for i in self.arr:
            res = max(res,i*(node_sum-i))  # 对集合arr中的值进行遍历
                                           # 由于arr中的值为每个子树的总和
                                           # sum - 子树总和即为剩余部分的总和
                                           # 两者相乘即为分裂二叉树的乘积
                                           # 获取最大的乘积结果即可

        res %= (10**9+7)                   # 求模

        return res
```


![微信截图_20200203080528.png](https://pic.leetcode-cn.com/2274df7cd5afee4a433a1b407bd4577bf75ec40298cb38b2fdaedba0bc63f0c7-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200203080528.png)
