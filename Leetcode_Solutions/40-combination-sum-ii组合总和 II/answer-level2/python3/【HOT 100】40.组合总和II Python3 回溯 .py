### 解题思路
- **相似题型**
- **回溯三要素**
- **代码**

### 相似题型
[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)
[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)
[78.子集](https://leetcode-cn.com/problems/subsets/solution/hot-100-78zi-ji-python3-hui-su-liang-chong-jie-ti-/)
[90.子集II](https://leetcode-cn.com/problems/subsets-ii/solution/hot-100-90zi-ji-ii-python3-hui-su-kao-lu-zhong-fu-/)
[22.括号生成](https://leetcode-cn.com/problems/generate-parentheses/solution/hot-100-22gua-hao-sheng-cheng-python3-hui-su-kao-2/)
[39.组合总和](https://leetcode-cn.com/problems/combination-sum/solution/hot-100-39zu-he-zong-he-python3-hui-su-kao-lu-jian/)

### 回溯三要素

这道题是基于[39.组合总和]()来的，那么基本思路和它其实是一样的，但是在[39.组合总和]()的基础上，有了新的要求：

- 有重复元素，但`candidates` 中的每个数字在每个组合中只能使用一次
- 解集不能包含重复的组合

在经历了那么多回溯大礼包之后，我们要有这样的惯性思维：当遇到重复元素题型但解集不能包含重复的组合的时候，我们一定要考虑**对数组排序**和**当当前元素和前一个元素相同且前一个元素未被使用的时候，我们需要剪枝**

依然是**小trick时间**：
`我们只需要考虑上一个相同元素的使用情况，那么我们就不需要像[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)那样用一个check数组来保存其他元素的使用情况，我们只需要知道上一个元素的情况，那么就可以只使用一个变量来记录，而不需要额外的数组空间`

好了第二个要求其实我们已经知道了，这道题相比于[39.组合总和]()来说，我们只多了一个**排序**和**剪枝条件**，那么第一个要求呢，每个数只能使用一次，那么说明**回溯范围**有了变化，下一层的回溯的遍历不能从index开始了，而需要从当前元素的索引+1的位置开始了

于是就很好分析了，尤其是有了[39.组合总和]()的基础，我们就很好的知道了相同和不同，也就可以很好的分析这道题的回溯三要素了

- **有效结果**
有效结果依然是：`当target==0的时候`，就是我们找到了一段满足条件的答案：
```
if tar == 0:
    self.res.append(sol)
    return
```

- **回溯范围及答案更新**
前提条件是`当tar>0的时候`，我们才会继续回溯搜索，只是我们下一轮回溯不能再使用当前元素了，于是就在下一轮的回溯范围里把当前元素剔除，也就是i+1，从下一个元素开始回溯：
```
if tar > 0:
    for i in range(index, len(nums)):
        self.backtrack(sol+[nums[i]], i+1, tar-nums[i], nums, check)
```

- **剪枝条件**
原条件依然是：`当当前数字已经>target的时候`，就不需要再继续回溯
现在只是增加了一个避免重复的问题：当当前元素和前一个元素相同且前一个元素未被使用的时候，我们需要剪枝
```
if tar > 0:
    for i in range(index, len(nums)):
        if nums[i] > tar:
            break
        if i > 0 and nums[i] == nums[i-1] and check == 0:
            continue
        check = 1
        self.backtrack(sol+[nums[i]], i+1, tar-nums[i], nums, check)
        check = 0
```



### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.res = []
        self.backtrack([], 0, target, candidates, 0)
        
        return self.res
        
    def backtrack(self, sol, index, tar, nums, check):
        if tar == 0:
            self.res.append(sol)
            return 
        
        if tar > 0:
            for i in range(index, len(nums)):
                if nums[i] > tar:
                    break
                if i > 0 and nums[i] == nums[i-1] and check == 0:
                    continue
                check = 1
                self.backtrack(sol+[nums[i]], i+1, tar-nums[i], nums, check)
                check = 0
```
![image.png](https://pic.leetcode-cn.com/29fe49dd082d450899a51152bf87f26a4c907426f15029ff07f9d54b9926469f-image.png)


### 小担忧
还是不知道怎么在职场生存，但是我有了新的目标：
第一：多读多理解《被讨厌的勇气》所讲的一些适用的信息
第二：我一定要尽快在LC英文版上有排名，冲进10w，大概还有100道题的距离叭哈哈哈哈哈哈