### 解题思路
#### 回溯-递归，错误
这里递归的代码很像之前的一个题目 [39. 组合总和](https://leetcode-cn.com/problems/combination-sum/) 自己写的代码

最开始以为是按照前面的组合题[39. 组合总和](https://leetcode-cn.com/problems/combination-sum/) 根据回溯法进行求解，后来发现回溯法写出来的代码简化后就是蛮力递归。效率极低。
连 [1,2,4] 32 都算不出来。

#### 无法通过的代码, 知识点： nonlocal count ， count += 1

``` python3  
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
    ## 回溯的复杂度几乎是指数级别的， [4,1,2] 32 这个例子都过不了
    ## 大量重复子问题
    ## 这一题该用动态规划
    ## 神奇！

        def dfs(rest):
            nonlocal res

            if rest == 0:
                res += 1
                return
            if rest<min(nums):
                return
            for i in nums:
                dfs(rest-i)
        
        if nums == []:
            return 0
        res = 0  # 好奇怪啊， res = [] 可以直接在子函数中用 res.append()，这个没有重赋值，仍然是一个数组
        # 但 res = 0， 在子函数中直接 res += 1, 就会报错。
        dfs(target)
        return res
```

#### 后来想到应该统计已经计算好的重叠子问题，不应该重复计算。应该使用带备忘录的递归，or 动态规划
带备忘录的递归在先前的一个题的题解中提到过。


这就很像硬币找零题了 [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

不过一个是统计最少用的硬币数量，一个是统计所有可能的找零方式，顺序不同的序列也算不同。






### 代码

```python3
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        ## 和 排列coin题 以及 完全平方数题 很像。
        # 枚举最后一个数 in nums:
       
        nums.sort()
        hash_set = dict() # 用来记录已经算出来的可能情况
        for i in range(1, target+1):
            hash_set[i] = 0
            for x in nums:  # 枚举最后一个数字，这样就可以统计 顺序不同的序列，
                if x > i:
                    break
                if x == i:
                    hash_set[i] += 1
                if x<i:
                    hash_set[i] += hash_set[i-x]
        
        # nums.sort() 错把这个放后面了，以为还是子函数
        return hash_set[target]
```