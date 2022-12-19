（1）因为刚开始学习动态规划，所以还不会定义什么状态转移方程，也不知道怎么看状态。就准备用递归来做的。
### 递归实现
```
class Solution(object):
    def minimumTotal(self, triangle):
        bottom = len(triangle)-1
        width = len(triangle[-1])
        def recursion(i, j, total):
            total += triangle[i][j]
            if i == bottom:   
                return total
            else:
                left = recursion(i+1, j, total)
                right = recursion(i+1, j+1, total)
                return min(left, right)
        return recursion(0, 0, 0)
```
果然，递归诚不欺我，最后一个测试实例超时了……
**思路也非常简单，就是先左后右，就像DFS一样，最后返回一个最小值作结果。**

（2）然后就想着尝试存储式的递归来优化，一开始想的是将 *dictionary[str(i)+str(j)] = min(left, right)*，结果运行出错，打开IDE debug了一下，发现字典里面存储的都不是什么正确的答案，因为DFS不像BFS那么有层次感，所以回溯的时候会会记录下错误的答案。

代码如下：
### 缓存的递归实现
*这串代码有问题*
```
class Solution(object):
    rets = {}

    def minimumTotal(self, triangle):
        bottom = len(triangle)-1
        return self.recursion(triangle, 0, 0, 0, bottom)

    def recursion(self, triangle, i, j, total, bottom):
        total += triangle[i][j]
        if self.rets.get(str(i)+str(j)):return self.rets[str(i)+str(j)]

        print(self.rets)
        if i == bottom:
            return total
        else:
            left = self.recursion(triangle, i+1, j, total, bottom)
            self.rets[str(i+1)+str(j)] = left
            right = self.recursion(triangle, i+1, j+1, total, bottom)
            self.rets[str(i+1)+str(j+1)] = right
            ret = self.rets[str(i)+str(j)] = min(left, right)
            return ret

```
这是测试用例：`[[2],[3,4],[6,5,7],[4,1,8,3]]`
结果如下：(20 代表第 2 行的第 0 列的结果为12，很明显不正确，有兴趣的可以自己用ide调试一下。)

![recu.jpg](https://pic.leetcode-cn.com/158245e68d937dcae76e1782fb60c6b9afc283371218e5501b40d056dcce5463-recu.jpg)

原谅我自身水平不够，想不到什么好的缓存办法，就放弃了这个解法。**如果有大佬知道怎么解，欢迎在评论区留言，谢谢！**

（3）然后看到别人用的动态规划，就学了一下怎么写，**定义状态，写状态转移方程，分析状态转移方程中的特例，实现。** 
花了挺长时间，在IDE上测试，最后终于写出能用的代码。如下：

### 常规动态规划
```
class Solution(object):
    def minimumTotal(self, triangle):
        if len(triangle) == 0:return 0
        if len(triangle) == 1:return triangle[0][0]     #特例考虑

        dp[0][0] = triangle[0][0]
        dp[1][0] = triangle[0][0] + triangle[1][0]
        dp[1][1] = triangle[0][0] + triangle[1][1]      #dp特例填充

        for idx1, ele1 in enumerate(triangle):
            for idx2, ele2 in enumerate(ele1):
                if idx1 > 1:
                    if idx1 > idx2 >= 1:
                        dp[idx1][idx2] = min(dp[idx1-1][idx2-1], dp[idx1-1][idx2]) + triangle[idx1][idx2]
                    elif idx2 == 0:
                        dp[idx1][idx2] = dp[idx1-1][idx2] + triangle[idx1][idx2]
                    else:
                        dp[idx1][idx2] = dp[idx1-1][idx2-1] + triangle[idx1][idx2]
        return min(dp[-1])
```
思路借鉴了 @浩仔讲算法， 不过他用的是GO实现的，我看了思路然后自己用Python实现的。
大体就是 

    1. 先创建一个全零填充的Triangle拷贝列表dp
    2. 然后将dp中的特殊情况先进行填充
    3. 自上而下遍历Triangle，根据  `dp[idx1][idx2] = min(dp[idx1-1][idx2-1], dp[idx1-1][idx2]) + triangle[idx1][idx2]` 转台转移方程来实现列表元素的相加，但是会有特例，也就是每一行的开头和结尾，所以要做特殊情况考虑，
    4. 最后返回dp最后一行的最小值，即解

（4）提交之后又看别人代码（代码来自 提交记录）
### 改进版动态规划
```
class Solution(object):
    def minimumTotal(self, triangle):
        dp = triangle                   #这边的初始化真的是牛逼，不仅不需要把把上面两行特殊的情况考虑进去，而且为下面也做了铺垫。       
        m = len(dp)

        for i in range(1, m):
            for j in range(i+1):
                if j == 0:
                    dp[i][j] += dp[i-1][j]          #承接上面，妙啊！   
                if j> 0 and j == i:
                    dp[i][j] += dp[i-1][j-1]
                    
                elif (j > 0 and j < i):
                    dp[i][j] += min(dp[i-1][j-1],dp[i-1][j])
        return (min(dp[-1]))
```
一个`dp = triangle` 就节省了好多代码，真的是绝妙，不需要初始化，就直接赋值，真的很强。

再之后，看了一下评论区大佬……

```
class Solution(object):
    def minimumTotal(self, triangle):
        for i in range(len(triangle)-2, -1, -1):
            for j in range(len(triangle[i])):
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])
        return triangle[0][0]
```

代码来自评论区第一个 @echo，ta是用CPP写的，我用python做了改编。
不需要新建列表，直接在Triangle上操作，在算法上是真的精妙，(PS: 要是在实际开发中这么写感觉会被骂啊，233) 整体思路和上面的动态规划一致，但是算法简洁度上是真的精妙。


### 总结
学习讲究循序渐进，一开始确实会非常艰难，但是学习中那种 山穷水尽疑无路，柳暗花明又一村 的感觉真的是开心，同时，那种看到别人精妙的代码，不由得心生敬佩，大呼精彩，这或许就是学习的乐趣吧。


