32ms, 98.29%, 缺点：内存占用较大
做题思路如下：
   题目要求的结果为每个node i(i∈[1, n])为树的root情况构成二叉树的个数之和,同时从node1-node(i-1)将去构成当前以i为根节点的树的左子树，
而node(i+1)-node(n)将去构成右子树。因为每次有node i 分割出的左右两部分都按大小顺序递增排序好了，所以左右子树能构建成不同结构的数量也
只和含有的node数量有关，因此将大问题转换为小问题即可以进行动态规划。
   方程可表示为从1开始遍历到n，dp[n] = sum(d[i - 1] * d[n - (i + 1)]))
    
代码如下：
    class Solution:
```
class Solution:
    def numTrees(self, n: int) -> int:
        # 初试表值对应n=0,1,2的情况
        dp = [1, 1, 2]
        for tmp_n in range(3, n + 1):
            tmp_sum = 0
            '''
            只需要遍历一半，因为具有对称关系，为偶数情况直接*2， 为奇数情况加上动态表最中间值的平方
            (举例：如对于n=5, 当遍历到node3的时候,node1,2去构成左子树，node4,5去构成右子树，
            node1,2能构成的树结构和node3,4能构成的树结构数量是一样的，即再加上dp[2]的平方])
            '''
            half = int(tmp_n / 2)
            for i in range(0, half):
            # 左右子树构成结构数量互不相关因此相乘得到每次的最终能构成的数量
                tmp_sum += dp[i] * dp[tmp_n - 1 - i]
            tmp_sum *= 2
            if tmp_n % 2 != 0:
                tmp_sum += dp[half] * dp[half]
            dp.append(tmp_sum)
        return dp[n]
```
    