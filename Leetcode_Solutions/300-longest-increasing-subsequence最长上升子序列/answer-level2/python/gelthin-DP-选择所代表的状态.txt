### 解题思路
剑指 offer 上似乎有这个题目。


最开始没有选择好 DP[i] 所代表的状态，导致代码很复杂还一直出错。也不知道错在哪里了。

#### DP[i] 代表以 nums[i] 为结尾的最长递增字符串的长度。
这个代码就非常好写，并且不需要记录结尾处的最大值。
但后续还要进行一次遍历，求出 max(DP)



#### DP[i] 代表 nums[0:geli+1] 中的最长递增字符串的长度。 
这个递归方程就非常难，还要记录这一长度所对应的最大 val, 方便后面进行比较。最终结果就是 DP[-1]

但我 code 写了好几次都写错了。





### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        DP = []   # DP[i] 以 第 i 个元素为结尾的最长上升子序列
        for i in range(n):
            DP.append(1)
            for j in range(i):
                if nums[j] < nums[i]:
                    DP[i] = max(DP[j]+1, DP[i])
        return max(DP) 
```

##### 有错误的代码 [3,5,6,2,5,4,19,5,6,7,12] 过不去
```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        DP = []
        for i in range(0, len(nums)):
            length, max_val = 1, nums[i]
            for j in range(i):
                if (DP[j][1] < nums[i]):  # 所谓的上升必须严格单调，不是 不降
                        tmp_l = DP[j][0] + 1
                        tmp_val = nums[i]
                else: 
                    tmp_l = DP[j][0]
                    tmp_val = DP[j][1]

                if length < tmp_l or (length == tmp_l and max_val> tem_val):
                    length, max_val = tmp_l, tmp_val

            DP.append([length, max_val])
        return DP[-1][0]                

```