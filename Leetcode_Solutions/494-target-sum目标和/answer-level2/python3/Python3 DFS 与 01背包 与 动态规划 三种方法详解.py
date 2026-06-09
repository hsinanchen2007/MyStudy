> 这题几种方法都挺微妙的，只有寥寥几行却内涵乾坤。
> 这里汇总几种方法并稍作补充。

# DFS

## 思路
+ 利用`dfs深度优先搜索`
+ 设置一个哈希表（字典），键是一个元祖，元祖第一位是目前的和，第二位是目前的位数。值是这个元祖推导到最后能有多少个解。
+ 例如`d[(4,5)] = 1` 代表读到4位的时候，正好有一个解符合条件（那么在这个例子中符合条件的S就是5），然后倒导`d([3,5]) = 2` ......(在这种情况下，第4位是0，总共就4位)
+ 初始化节点为`(0,0)`，代表已经读了0位，现在和为0
+ 开始深度优先搜索，当i比位数小，说明可以深入。为了避免重复运算，要看当前节点是否在d里已经出现过。
+ 每次深入的结果，就是`d[(i, cur)] = dfs(cur + nums[i], i + 1, d) + dfs(cur - nums[i], i + 1, d)`。意思就是当前节点推导到最后有多少个可能性呢？这个节点再读取一位，要么是加上这一位，要么是减掉这一位，所以这个节点的可能性就是对加上下一位的可能性与减掉下一位的可能性之和。
+ 当深入到最后一位时，再深入就超了位数限制了，此时可以直接判断这个节点的和（即元祖的第二位）是否等于需要的S。是了为1，否则为0。因为`dfs`可能遍历到重复节点，所以`return`一行写作`d.get((i, cur), int(cur == S))`。如果是重复节点直接返回字典里对应值就完事儿(ง •̀_•́)ง
## 代码
+ 代码部分对原题解做了些许更改，消除了`d={}`，以免引起误解。原题解将`d={}`写在了dfs()函数里作为默认参数，让人感觉每次调用都是一个新字典，但是实际上传递的是形参，只有第一次调用才会是空字典。所有可变参数作为参数默认值都会造成这样的误解。
+ 同时调整了函数参数的顺序使得参数顺序和元祖顺序保持一致。
```Python
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        d = {}
        def dfs(cur, i, d):
            if i < len(nums) and (cur, i) not in d: # 搜索周围节点
                d[(cur, i)] = dfs(cur + nums[i], i + 1, d) + dfs(cur - nums[i],i + 1, d)
            return d.get((cur, i), int(cur == S))   
        return dfs(0, 0, d)
```
# 01背包

## 思路
原问题是给定一些数字，加加减减，使得它们等于`targert`。例如，`1 - 2 + 3 - 4 + 5 = target(3)`。如果我们把加的和减的结合在一起，可以写成
```
(1+3+5)  +  (-2-4) = target(3)
-------     ------
 -> 正数    -> 负数
```

所以，我们可以将原问题转化为： 找到`nums`一个正子集和一个负子集，使得总和等于`target`，统计这种可能性的总数。

我们假设P是正子集，N是负子集。让我们看看如何将其转换为子集求和问题：
```
                  sum(P) - sum(N) = target
                  （两边同时加上sum(P)+sum(N)）
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
            (因为 sum(P) + sum(N) = sum(nums))
                       2 * sum(P) = target + sum(nums)
```
因此，原来的问题已转化为一个求子集的和问题： 找到`nums`的一个子集 P，使得
$$
sum(P) = \frac{target + sum(nums)}{2}
$$

根据公式，若`target + sum(nums)`不是偶数，就不存在答案，即返回0个可能解。

因此题目转化为`01背包`，也就是能组合成容量为`sum(P)`的方式有多少种,一种组合中每个数字只能取一次。解决01背包问题使用的是`动态规划`的思想。

方法是
+ 开辟一个长度为`P+1`的数组，命名为`dp`
+ `dp`的第`x`项，代表组合成数字x有多少方法。比如说,`dp[0] = 1`，代表组合成0只有1中方法，即什么也不取。比如说`dp[5] = 3` ，代表使总和加到5总共有三种方法。
+ 所以最后返回的就是`dp[P]`，代表组合成P的方法有多少种

问题是

**怎么更新dp数组呢**？

+ 遍历`nums`，遍历的数记作`num`
    + 再逆序遍历从`P`到`num`，遍历的数记作`j`
        + 更新`dp[j] = dp[j - num] + dp[j]`
+ 这样遍历的含义是，对每一个在`nums`数组中的数`num`而言，`dp`在从`num`到`P`的这些区间里，都可以加上一个`num`，来到达想要达成的`P`。
+ 举例来说，对于数组`[1,2,3,4,5]`，想要康康几种方法能组合成4,那么设置`dp[0]`到`dp[4]`的数组
+ 假如选择了数字2,那么`dp[2:5]`（也就是2到4）都可以通过加上数字2有所改变，而`dp[0:2]`（也就是0到1）加上这个2很明显就超了，就不管它。
+ 以前没有考虑过数字2,考虑了会怎么样呢？就要更新`dp[2:5]`，比如说当我们在更新`dp[3]`的时候，就相当于`dp[3] = dp[3] + dp[1]`,即本来有多少种方法，加上去掉了2以后有多少种方法。因为以前没有考虑过2,现在知道，只要整到了1,就一定可以整到3。

**为什么以这个顺序来遍历呢**？
假如给定`nums = [num1,num2,num3]`，我们现在可以理解`dp[j] = dp[j-num1] + dp[j-num2] + dp[j-num3]`。

但是如何避免不会重复计算或者少算？要知道，我们的`nums`并不是排序的，我们的遍历也不是从小到大的。

我们不妨跟着流程走一遍
1. 第一次num1，仅仅更新了`dp[num1] = 1`，其他都是0+0都是0啊都是0
2. 第二次num2，更新了`dp[num2] = 1`和`dp[num1+num2] = dp[num1+num2] + dp[num1] = 1`,先更新后者。
3. 第三次num3，更新了`dp[num3] = 1`和`dp[num1+num3] += 1`和`dp[num2+num3] += 1`和`dp[num1+num2+num3] += 1`。按下标从大到小顺序来更新。
4. ......

由此可见，这种顺序遍历能得到最后的答案。这里可以跟着IDE的debug功能走一遍，加深理解。

## 代码
```java []
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        if (nums == null || nums.length == 0) return 0;
        int sums = 0;
        for (int num : nums) sums += num;
        if (sums < S || (S + sums) % 2 == 1) return 0;
        int p = (S + sums) / 2;
        int[] dp = new int[p + 1];
        dp[0] = 1;
        for (int num : nums) {
            for (int i = p; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[p];
    }
}
```
```python []
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if sum(nums) < S or (sum(nums) + S) % 2 == 1: return 0
        P = (sum(nums) + S) // 2
        dp = [1] + [0 for _ in range(P)]
        for num in nums:
            for j in range(P,num-1,-1):dp[j] += dp[j - num]
        return dp[P]
```
> 感谢[@wwssxxu](/u/wwssxxu/)提供的 Java 解法。
这个方法用时只有第一种`DFS`的十分之一，也只有第三种`DP`方法的十分之一。

# 动态规划

## 思路
这是一个纯动态规划的方法，比较烧脑，运算时间也没有第二种少。

+ 设置一个哈希表（字典），键是一个元祖，元祖第一位是目前的和，第二位是目前的位数。值是这个元祖推导到最后能有多少个解。
+ 例如`d[(4,5)] = 1` 代表读到4位的时候，正好有一个解符合条件（那么在这个例子中符合条件的S就是5），然后倒导`d([3,5]) = 2` ......(在这种情况下，第4位是0，总共就4位)
+ 因为符号要么全正，要么全负，所以元祖第二位的取值范围是 `-sum(nums) ~ sum(nums)`
+ 状态转移公式：
$$
dp[(i,j)] = dp.get((i - 1, j - nums[i]), 0) + dp.get((i - 1, j + nums[i]), 0)
$$
其实本质上就是没有使用递归的`dfs`。
## 代码
对原题解的代码做了比较大的调整
+ 将`dp`由`字典列表`改为了单纯的`元祖字典`，以和第一种`dfs`解法相一致。
+ 将底层字典赋值改为`(0,0):1`
+ 这个方法会生成很多不必要的节点，会浪费很多空间。
```Python
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        length, dp = len(nums), {(0,0): 1}
        for i in range(1, length+1):
            for j in range(-sum(nums), sum(nums) + 1):
                dp[(i,j)] = dp.get((i - 1, j - nums[i-1]), 0) + dp.get((i - 1, j + nums[i-1]), 0)             
        return dp.get((length, S), 0)
```

# 参考题解
### DFS
> 参考了这份题解
> https://leetcode-cn.com/problems/target-sum/solution/5xing-python-dfs-memory-by-knifezhu/
> 因为解释的部分有点少所以补充一下
### 01背包
> 参考了评论区第一的解答，作了一些更详细的补充。
> 参考了
> https://leetcode-cn.com/problems/two-sum/solution/dong-tai-gui-hua-cun-chu-mou-shu-chan-sheng-de-ci-/ 这份题解
### 动态规划
> 这个方法参考了https://leetcode-cn.com/problems/target-sum/solution/dong-tai-gui-hua-cun-chu-mou-shu-chan-sheng-de-ci-/