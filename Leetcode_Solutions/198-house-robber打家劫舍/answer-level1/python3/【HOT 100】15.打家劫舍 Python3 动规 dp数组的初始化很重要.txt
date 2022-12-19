
### 更新思路：很重要的一点，dp的初始化
第二次写这个题感觉思路没错啊，为什么就在`[2,1,1,2]`这个问题上错了呢，也确实是在找历史最大，但是为什么就拿不到预期结果，反而是要隔两家（`2,2`）才能拿到最优结果，结果是在初始化dp的时候错了
如果只有两家，肯定是偷max那一家，那么在初始化dp数组的时候，第二个元素也应该是max的值，而不仅仅只是第二个元素


## 分割线

### 1.动规

拿到这个题，简直无从下手，看着“简单”的tag很悲伤。。。

然后总觉得是用动规，但是当时想着逆序考虑整个数组，完全没想到顺序遍历

看了一下题解，发现就是类似背包（自我感觉类似。。）的动规问题

动规也需要考虑边界情况。。我第一次报错就是忘记了边界情况。。天真的愚蠢
当数组为空，返回0
当数组只有一个数的时候，返回这个值
当数组有两个值的时候，返回这两个值的max值

那当数组有三个数的时候呢
[1,2,3]，此时动规dp数组里面已经保存的是[1,2]
当遇到3这个房子的时候，我这个小偷是偷还是不偷呢？
假设有个小偷跟我一起偷，我偷到一个房子，他就偷到我前一个房子刚好挨着，但是我每次都比他快，偷在他前面
那当我遇到一个房子的时候，我就需要考虑我旁边这个小偷偷了多少钱，要是他偷的钱比我之前的钱加上当前这个房子的钱还要多，那我不如不偷我这个房子了，我去他那条路线更划算，但是如果他的钱比我少，我还是继续偷我这条路线了
于是我们在遇到i个房子的时候，就要考虑之前偷的总钱数的dp[i-1]和dp[i-2]的值的情况
找到max(dp[i-2]+money(i), dp[i-1]) 这会是我新的钱（把那个小偷的钱抢过来。。。）

那么我知道怎么初始化这个dp数组了，
第一个数就是第一间房子的钱，第二个数就是max(第一间房子的钱，第二间房子的钱），从第三个数开始就需要判断我怎么偷这个钱了
我得去找最多的钱也就是`dp[i] = max(dp[i-1], dp[i-2]+nums[i])`
其实动规最需要考虑的状态转移方程就是“选或不选的问题”，选了这个我怎么办，不选这个我怎么办
（怎么又是选择问题。。。最近刚经历手抖选太早的问题。。切记：一定要找最优解，不能贪心哈哈哈哈）

这里的问题就是，遇到i这个房子，我选，和不选的问题，如果我选，那么就是只能去累加这个房子间隔一个房子之前的所有钱：大概这么个意思吧:
![image.png](https://pic.leetcode-cn.com/d5267d9bd0e792b7cecef308e9d1af9890832c1ad6ba7c579bdfd26addbb4fbc-image.png)

如果我不选，那么就只能去拿到前一个相邻房子及之前的所有钱：
![image.png](https://pic.leetcode-cn.com/0524c7a881d2ce0df1f7f30432e0795d304a277375ff2031d4facd94adabcca8-image.png)

我要找最大，那就是max（选，不选），于是就可以写出如下代码：

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        dp = [nums[0], max(nums[0], nums[1])]
        
        for i in range(2, len(nums)):
            dp.append(max(dp[i-1], nums[i]+dp[i-2]))
            
        return dp[-1]
```

但是一提交，我的天。。。这么慢吗，**时间复杂度O(n)，空间复杂度O(n)**，能不能优化一下。。。

![image.png](https://pic.leetcode-cn.com/cceb5d84bd24976ef7d985e260fa19af86720c465dd9d18cc8ac1042dc1800b4-image.png)


### 2.优化：减少空间复杂度

怎么优化呢？突然想到了当时做跳台阶的斐波那契问题，明明是可以用斐波那契的更新方式，我非要用一个dp数组来疯狂append。。。这里好像有点相同的意思，能够不用数组保存值，只用两个变量就可以的感觉。。
试试，把dp里面的两个数拿出来，
比较麻烦的是如何更新pre_max，因为dp数组在疯狂append，其实就是在往后挪，那么pre_max和cur_max也往后挪就好了
pre往后挪就是cur，cur往后挪就是新的最大值：

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        # dp = [nums[0], max(nums[0], nums[1])]
        
        pre_max = nums[0]
        cur_max = max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            # dp.append(max(dp[i-1], nums[i]+dp[i-2]))
            pre_max, cur_max = cur_max, max(cur_max, pre_max+nums[i])
            
            
        return cur_max
```

再次提交之后好了很多很多，希望我的生活也能因为再次提交而好很多很多（一个没有追求只想去北京的菜鸡。。。）

![image.png](https://pic.leetcode-cn.com/71a450fb34698087e71dbcfea6a0de6c268cb51ee0e1bef23fdf2325e3627bea-image.png)
