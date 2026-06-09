### 解题思路
- **相似题型**
- **回溯三要素**
- **代码**

### 相似题型
怎么可以少了回溯小分队呢：
[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)
[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)
[78.子集](https://leetcode-cn.com/problems/subsets/solution/hot-100-78zi-ji-python3-hui-su-liang-chong-jie-ti-/)
[90.子集II](https://leetcode-cn.com/problems/subsets-ii/solution/hot-100-90zi-ji-ii-python3-hui-su-kao-lu-zhong-fu-/)
[22.括号生成](https://leetcode-cn.com/problems/generate-parentheses/solution/hot-100-22gua-hao-sheng-cheng-python3-hui-su-kao-2/)


### 回溯三要素
`当遇到sum和的问题的时候，我们其实可以反向考虑，不用去每次求sum，判断sum是否等于target，而是我每一次都让target减去当前元素的值，用判断target是否等于0来决定是否找到了答案`：

![image.png](https://pic.leetcode-cn.com/fe9376f52181b60311582c0c392c838ae37ec896069b3510bea372191caaa7aa-image.png)

首先我们是需要遍历所有元素的，因为每个元素开头都可以作为一个答案的第一个值，第一种情况，当i=0的时候，此时元素为2【以2开头】，于是`剩余要填补的target的值就为7-2=5`，然后我们继续寻找，又由于**答案是可以重复选择元素**的，所以接下来还是`从i=0一直到i=len(nums)遍历`：

1.当第二个元素选择2时，剩余target=5-2=3，此时还没有=0，且还>0，说明还没有找到结果，继续遍历：
&emsp;1.1 当第三个元素选择2时，剩余target=3-2=1，此时还没有=0，且还>0，说明还没有找到结果，继续遍历：
&emsp;&emsp;1.1.1 当第四个元素选择2时，发现2大于了我们的剩余target，说明其实我们不需要继续找了，因为这个值已经大了

于是这就是我们的**第一个trick**：
`首先要让数组排序，让元素从小到大排列，这样当我们遇到当前数字已经比target大的时候，就不需要再继续回溯，直接可以中断循环，之后的元素也不需要再遍历，因为之后的元素只可能比当前元素更大`

来考虑一个**符合条件**的情况：
1.当第一个元素选择2时，第二个元素选择2时，第三个元素除了上面的我们继续选择2的情况，我们还可以选择3作为第三个元素，此时剩余tar=0，也就是我们的想要的答案

于是我们大概可以发现这里有`三种考虑情况`：
- 1.**当当前值小于target的时候，我们继续回溯搜索**
- 2.**当当前值等于target的时候，我们找到答案**
- 3.**当当前值大于target的时候，我们剪枝，并且是break而不是continue的剪枝，因为已经是排序后的数组，之后的值会比当前值更大，更不需要被考虑**

于是也就可以很好的想到我们的`回溯三要素`：


- **有效结果**
于是我们的有效结果就可以算作：`当target==0的时候`，就是我们找到了一段满足条件的答案：
```
if tar == 0:
    self.res.append(sol)
    return
```

- **回溯范围及答案更新**
`当tar>0的时候`，我们才会继续回溯搜索
```
if tar > 0:
    for i in range(index, len(nums)):
        self.backtrack(sol+[nums[i]], i, tar-nums[i], nums)
```

- **剪枝条件**
`当当前数字已经>target的时候`，就不需要再继续回溯
```
for i in range(index, len(nums)):
    if nums[i] > tar:
        break
    self.backtrack(sol+[nums[i]], i, tar-nums[i], nums)
```


### 代码（不考虑剪枝）
```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.res = []
        self.backtrack([], 0, target, candidates)
        
        return self.res
        
    def backtrack(self, sol, index, tar, nums):
        if tar == 0:
            self.res.append(sol)
            return
        
        if tar > 0:
            for i in range(index, len(nums)):
                self.backtrack(sol+[nums[i]], i, tar-nums[i], nums)
```
![image.png](https://pic.leetcode-cn.com/f1925d39e72bebca4adf3c3feaa18692731e290883406ece650c2db5735ea293-image.png)

![image.png](https://pic.leetcode-cn.com/943bb16bc34abfaa12dceade3e04dae5c639215439d64415d05483ae52eb7e4d-image.png)


### 剪枝优化后代码

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        '''非常重要'''
        candidates.sort()

        self.res = []
        self.backtrack([], 0, target, candidates)
        
        return self.res
        
    def backtrack(self, sol, index, tar, nums):
        if tar == 0:
            self.res.append(sol)
            return
        
        if tar > 0:
            for i in range(index, len(nums)):
                if nums[i] > tar:
                    break
                self.backtrack(sol+[nums[i]], i, tar-nums[i], nums)
```
![image.png](https://pic.leetcode-cn.com/808547f414fc6f1a64b3c47a43795601eb82bc80ec668a9eb543656bdf99e004-image.png)


### 总结
这周是疯狂赶进度的一周，一定要珍惜！
还要开始准备读博的相关资料，从现在开始才不晚
缺少了太多能力，一定要加油赶起来呀