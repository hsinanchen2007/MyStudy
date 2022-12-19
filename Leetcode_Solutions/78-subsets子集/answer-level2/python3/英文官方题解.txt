## [题解](https://leetcode.com/problems/subsets/solution/)

------

#### 此类问题答案套路

让我们首先回顾一下排列/组合/子集问题，它们彼此非常相似，有一些通用的策略可以解决此类问题。 首先，此类问题的解空间通常很大：

- [排列](https://en.wikipedia.org/wiki/Permutation#k-permutations_of_n): $N! $ 
- [组合](https://en.wikipedia.org/wiki/Combination#Number_of_k-combinations): $ C_N^k = \frac{N!}{(N - k)! k!} $ 
- 子集: $ 2^N$ ，每个元素可能不存在或存在。

它们的解空间呈指数增长，要确保生成的解决方案**完整**且**非冗余**，需要些策略技巧。 

通常有三种解空间生成策略：

- 递归
- 回溯
- 基于二进制位掩码与相应排列/组合/子集之间的映射的解空间词典生成。 

稍后将看到，第三种方法是面试的一个很好的候选，因为它将原问题简化为生成二进制数问题，易于实现，确保没有遗漏任何解决方案。 

此外，此方法具有最佳的时间复杂度，此外，它还为有序输入生成字典序输出。 

------

#### 方法1：递归

**直观解释**

让我们从输出列表中的空子集开始。 在每一步中，都要考虑新的整数，并从现有子集中添加这个整数生成新的子集。

![diff](https://pic.leetcode-cn.com/01f1ebca88a7e2b7846fab0699b4aae9af471a33e40c70ac2c90e9c5b2acc670.png)

**实现**

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        output = [[]]
        
        for num in nums:
            output += [curr + [num] for curr in output]
        
        return output
```
------

#### 方法2：回溯

**算法**

> 幂集是从0到n的所有可能长度的所有可能组合。



让我们遍历**集合元素个数**，并借助**回溯**技术生成给定个数的所有集合。

![diff](https://pic.leetcode-cn.com/bf8b120a0bb9e37bdf262f1a10f86564772ec7a1d16e612aea2cb6442f0825de.png)

> [回溯](https://en.wikipedia.org/wiki/Backtracking)是一种通过探索所有潜在候选者来找到所有解的算法。 如果候选解决方案不是解（至少不是最后一个解），则回溯算法会通过对上一步（即**回溯**）上进行一些更改来退出当前方案，然后再去尝试其它方案。

![diff](https://pic.leetcode-cn.com/5367d29d5104d53d4aa5fdb7a884344d5d531680e18253600bca23f07e095502.png)

**算法**

我们定义一个回溯函数`backtrack(first, curr)`，该函数以要添加的第一个元素的下标和当前组合作为参数。

-  如果完成了当前组合，则将组合添加到最终输出中。

-  否则，我们从`first`到序列长度`n`的范围迭代`i`。 

   - 将`nums[i]`**添加**到当前组合`curr`中。 
   - 继续向组合中添加更多整数：`backtrack(i + 1, curr)`。 
   - 通过从`curr`中删除`nums[i]`进行**回溯**。 

**实现**

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first = 0, curr = []):
            # if the combination is done
            if len(curr) == k:  
                output.append(curr[:])
            for i in range(first, n):
                # add nums[i] into the current combination
                curr.append(nums[i])
                # use next integers to complete the combination
                backtrack(i + 1, curr)
                # backtrack
                curr.pop()
        
        output = []
        n = len(nums)
        for k in range(n + 1):
            backtrack()
        return output
```
对比：下面是递归，但其实并没有回溯
```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        
        def helper(i, tmp):
            res.append(tmp)
            for j in range(i, n):
                helper(j + 1,tmp + [nums[j]] )
        helper(0, [])
        return res  

作者：powcai
链接：https://leetcode-cn.com/problems/subsets/solution/hui-su-suan-fa-by-powcai-5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



------

#### 方法3：基于二进制位掩码子集生成

**直觉**

此解决方案的思想源自[Donald E. Knuth](https://www-cs-faculty.stanford.edu/~knuth/taocp.html)。

>  我们将每个子集映射到长度为n的位掩码，其中位掩码中第i个位置上的1表示子集中存在nums [i]，而0表示不存在。

![diff](https://pic.leetcode-cn.com/ad9b3636eacf6d4e99e778d7affcd38b1120a6cd7095455831cef7c5707eb959.png)

例如，位掩码0..00（全零）对应于一个空子集，而位掩码1..11（全零）对应于整个输入数组num。

 因此，要解决原问题，我们只需要生成从0..00到1..11的所有n位掩码。 

乍一看，生成二进制数似乎很简单，但是这里的问题是如何处理[零左填充](https://en.wikipedia.org/wiki/Padding_(cryptography)#Zero_padding)，因为必须生成固定长度的位掩码，即001，而不仅仅是1。为此，可以使用标准位操作技巧：
```python
nth_bit = 1 << n
for i in range(2**n):
    # generate bitmask, from 0..00 to 1..11
    bitmask = bin(i | nth_bit)[3:]
```

或者改变迭代范围：
```python
for i in range(2**n, 2**(n + 1)):
    # generate bitmask, from 0..00 to 1..11
    bitmask = bin(i)[3:]

```


**实现**
```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        output = []
        
        for i in range(2**n, 2**(n + 1)):
            # generate bitmask, from 0..00 to 1..11
            bitmask = bin(i)[3:]
            
            # append subset corresponding to that bitmask
            output.append([nums[j] for j in range(n) if bitmask[j] == '1'])
        
        return output
```

一个通俗易懂的实现：
```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans,n = [],len(nums)
        for i in range(1<<n):
            temp = []
            for j in range(n):
                if (i>>j) & 1 ==1: temp.append(nums[j])
            ans.append(temp[:])
        return ans

作者：keyianpai
链接：https://leetcode-cn.com/problems/subsets/solution/an-quan-di-yi-an-quan-di-yi-by-keyianpai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

