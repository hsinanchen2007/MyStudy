### 解题思路
本题解题核心思想：木桶效应，左右两边同时向最高点趋近。

### 法一：
你可以将3个柱体想象成一个水桶，两边分别为木板，中间为水。然后要满足里面有水的条件，就可以联想到木桶效应，只需要水面低于等于两边最短的木板高度，就说明会有水。接着我们把它扩展到全局，只要当前位置高度低于等于两边所有柱体的中最短的木板高度，就说明该位置相对于两边最短柱体是属于低地势的。

所以由此推出了某一柱体中有水的条件。令当前柱体高度为`cur`,令其左边所有柱体的高度最大值为`max_left`,令其右边所有柱体的高度最大值为`max_right`,所以条件：cur > max(max_left,max_right),说明当前位置会有积水，令总积水为`sums`,则sums += cur - max(max_left,max_right)。

有了这个条件，接下来就是循环求sums,我们先不急遍历，我们先想一下，对于这种出现与左右两边都要相关的问题，我们是否可以通过可以从左右两边分开遍历？这样的话时间复杂度会不会相对的减少很多？答案对于法一来说是肯定的，接下来我们来分析一下。

首先从头到尾正向遍历,部分代码：
```python
 for i in range(1,len(height)-1):
        # 此时首位都是高度>0的柱子，不用考虑它们会产生雨水
        max_left = max(height[:i])
        max_right = max(height[i+1:])
        if max_left > height[i]:
            sums += max_left - height[i]
```
这段代码的时间复杂度为O(n²),主要优化的地方为max()函数

**python3消耗的时间：**
![图片.png](https://pic.leetcode-cn.com/49084db62a5b65c8deb4d0d6faacb9df8809e904416b0813f1b8241aaa3fde2d-%E5%9B%BE%E7%89%87.png)


接下来看正反遍历，部分代码：
```python
 # 遍历最大值的左边
    for i in range(1,max_index):
        list_[i] = max(list_[i-1],height[i-1])
        # 因为遍历最高点的左边，所以listl_left[i]即为左右中的最小值
        if list_[i] > height[i]:
            sums += list_[i] - height[i]
        # 遍历最大值的右边
    for i in range(len(height)-2,max_index,-1):
        list_[i] = max(list_[i+1],height[i+1])
        if list_[i] > height[i]:
            sums += list_[i] - height[i]
```
这段代码中虽然时间复杂度最坏的情况下也为O(n²),但是在最好的情况中，max()中产生的复杂度会比上一段代码小很多。

**python3消耗的时间：**
![图片.png](https://pic.leetcode-cn.com/6de1ba35ebb07208bc29294e39a27c9966a2e1ebcd6ae3b9b49d7375985ae169-%E5%9B%BE%E7%89%87.png)

### 法二：动态规划：
动态规划的思想主要看该题是否存在状态转移，通过仔细推敲，我们可以发现，如果我们每次将两边最大的值保存下来，就可以避免时间复杂度为O(n)的max(list)函数了。
状态转移方程：dp[i] = max(dp[i-1],num_left),num_left为当前位置的左边最高高度
             dp[i] = max(dp[i+1],num_right),num_right为当前位置的右边最高高度
这里采用左右两边分开遍历的妙处在于：
①对于左边遍历来说，右边的最高度恒为峰点
②对于右边遍历来说，左边的最高度恒为峰点
因此我们首先求出峰点，然后根据法一的思想进行条件比较，求出积水sums


![图片.png](https://pic.leetcode-cn.com/e10ba955503eebba3d485cb2de402f65afd00adc729b7fb65e6bba365d577e81-%E5%9B%BE%E7%89%87.png)

### 法三：双指针
双指针通常用于解决数组的问题，降低空间复杂度。这里主要为了将法二中的dp换成常数cur。具体思想是一样的。可以参考下面的代码。

![图片.png](https://pic.leetcode-cn.com/e34cc69bc0bb1a52108de56b131b812ccb0a3486962a0cf91a751386daa94d7c-%E5%9B%BE%E7%89%87.png)



### 三种算法复杂度分别如下：

**按照列正向迭代：**
时间复杂度：O（n²）
空间复杂度：O（1）

**动态规划**
时间复杂度：O（n）
空间复杂度：O（n）


**双指针**
时间复杂度：O（n）
空间复杂度：O（1）






### 代码

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        
        # 高度差问题
        # 法一：按列求，根据木桶效应
        if not height:
            return 0
        max_index = height.index(max(height))
        # m,n = 0,0
        # 去除左右两边为0的柱子
        # 法一：按列求，根据木桶效应
        sums = 0
        for i in range(max_index):
            if height[i] != 0:
                del height[:i]
                break
        for i in range(len(height)-1,max_index,-1):
            if height[i] != 0:
                del height[i+1:]
                break
        max_index = height.index(max(height))
        for i in range(1,max_index):
            # 此时首位都是高度>0的柱子，不用考虑它们会产生雨水
            max_left = max(height[:i])
            if max_left > height[i]:
                sums += max_left - height[i]
        for i in range(len(height)-2,max_index,-1):
            max_right = max(height[i+1:])
            # 根据木桶效应，选取最短的那一端
            if max_right > height[i]:
                sums += max_right - height[i]
        return sums
        
```

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        # 法二:利用动态规划
        # 观察是否存在状态转移
        # 根据法一和木桶效应可以得出，当前位置的积水会由左边和右边的最小值决定
        # dp[i]表示当前位置的前面数的最大值
        # dp[i] = max(dp[i-1],height[i-1])
        if not height:
            return 0
        max_index = height.index(max(height))
        # 修正左边起始位置为第一个不为0的数
        for i in range(max_index):
            if height[i] != 0:
                del height[:i]
                break
        # 修正右边起始位置为第一个不为0的数
        for i in range(len(height)-1,max_index,-1):
            if height[i] != 0:
                del height[i+1:]
                break
        sums = 0
        max_index = height.index(max(height))
        list_ = [0 for _ in range(len(height))]
        # 遍历最大值的左边
        for i in range(1,max_index):
            list_[i] = max(list_[i-1],height[i-1])
            # 因为遍历最高点的左边，所以listl_left[i]即为左右中的最小值
            if list_[i] > height[i]:
                sums += list_[i] - height[i]
        # 遍历最大值的右边
        for i in range(len(height)-2,max_index,-1):
            list_[i] = max(list_[i+1],height[i+1])
            if list_[i] > height[i]:
                sums += list_[i] - height[i]
        return sums
```

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        # 降低空间复杂度为0(1),采用双指针
        if not height:
            return 0
        max_index = height.index(max(height))
        for i in range(max_index):
            if height[i] != 0:
                del height[:i]
                break
        for i in range(len(height)-1,max_index,-1):
            if height[i] != 0:
                del height[i+1:]
                break
        max_index = height.index(max(height))
        sums = 0
        cur_max = 0
        for i in range(1,max_index):
            cur_max = max(cur_max,height[i-1])
            if cur_max > height[i]:
                sums += cur_max - height[i]
        cur_max = 0
        for i in range(len(height)-2,max_index,-1):
            cur_max = max(cur_max,height[i+1])
            if cur_max > height[i]:
                sums += cur_max -height[i]
        return sums
```