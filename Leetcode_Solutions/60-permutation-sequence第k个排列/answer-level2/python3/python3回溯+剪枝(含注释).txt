
#代码主体和思路学习于以下链接，做了部分代码顺序修改便于个人理解，以及添加了更多个人注释
https://leetcode-cn.com/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/

```python []
class Solution:

    def getPermutation(self, n: int, k: int) -> str:
        if n == 0:  #n的特殊情况判断
            return []  #则直接返回
        nums = [i + 1 for i in range(n)]  #根据n的大小,初始化nums数组,如:numns=[1,2,3,4]
        used = [False for _ in range(n)]  #并初始化used数组,用于标记各个数字是否已被使用,初始值:[False,False,False,False]
        res = []                          #保存路径上选择的各个节点值,如["2","3","1","4"]
        self.dfs(nums, used, n, k, res)   #开始dfs遍历,搜寻各个节点值添加进res中
        return ''.join(res)               #将所有节点值拼成最后完整结果,如2314,并返回

    #计算n!
    def factorial(self, n):
        # 这种编码方式包括了 0 的阶乘是 1 这种情况
        fac = 1  #初始化阶乘变量值
        while n:
            fac *= n
            n -= 1
        return fac  #返回n！计算结果

    #dfs遍历二叉树解空间中的合适解路径
    def dfs(self, nums, used, n, k, res):

        if len(res) == n:   #递归结束条件判断
            # 如果已经到达了叶子节点，则可以终止递归
            return res

        for i in range(n):

            # 如果这个数用过，就不再考虑
            if used[i]:
                continue #剪枝

            res.append(str(nums[i]))  #如果没有使用过,则添加当前元素,并判断后面还有几种排列结果
            ps = self.factorial(n - len(res)) #计算 (n-len(res))! 的阶乘结果

            # 如果后面的数的全排列的个数 小于 目标数k,则执行剪枝操作
            if ps < k:
                res.pop()  #回溯返回上一层
                k -= ps    #调整的k的范围
                continue   #剪枝

            #如果不剪枝,确定使用nums[i],则标记为True
            used[i] = True
            #并递归搜索到下一层,继续向res中添加下一层的选择
            return self.dfs(nums, used, n, k, res)

            # 因为直接走到叶子结点，因此状态不用恢复为False
```
