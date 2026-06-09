### 解题思路
- **相似题型**
- **两种解题思路**   
- **回溯三要素**
- **代码**
- **Trick：空间优化**


### 相似题型
[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)
[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)
[78.子集](https://leetcode-cn.com/problems/subsets/solution/hot-100-78zi-ji-python3-hui-su-liang-chong-jie-ti-/)

这道题和[78.子集](https://leetcode-cn.com/problems/subsets/solution/hot-100-78zi-ji-python3-hui-su-liang-chong-jie-ti-/)的关系就像是[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)和[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)的关系，这道题是另一题的升级版，添加了一个条件，也就是输入中会存在**重复元素**，于是我们依然延续初级版的解题思路，只是额外考虑一下重复情况如何剪枝的问题


### 思路1：全部考虑，选或不选
T为选择，F为不选择
![image.png](https://pic.leetcode-cn.com/5d2e625dbd3999366e75069e9bd9582c1ab2b013b7ce2ee41f68c48469f6b4ff-image.png)
看起来我们并不需要遍历，而是需要每一层都考虑一下当前元素的index对应的值，我们是要还是不要，依然是传入一个index元素用于指向当前层的元素索引【**回溯三要素之2.回溯范围**】

能够看出来灰色部分就是重复答案，红色框起来的部分就是重复答案的条件，也就是我们要提前就剪枝的部分，依然类似于[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)，发现当遇到重复元素，且上一个元素未被使用过，就需要剪枝【**回溯三要素之3.剪枝条件**】，依然可以用一个`check`变量来保存元素是否有被使用过

### 思路1：回溯三要素
结合[78.子集](https://leetcode-cn.com/problems/subsets/solution/hot-100-78zi-ji-python3-hui-su-liang-chong-jie-ti-/)和[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)就很好想到回溯三要素是什么了：

- **有效结果**
当指向元素的index==len(nums)的时候，就说明这一次的搜索结束了
```
if index == len(nums):
    self.res.append(sol)
    return
```
- **回溯范围及答案更新**
不需要循环遍历，而只需要用一个index指向每一次的元素，下一层更新index = index+1
对于答案更新，我们需要考虑选或不选当前答案，保存当前index指向的元素
```
self.backtrack(sol+[nums[index]], index+1, nums)  
self.backtrack(sol, index+1, nums)
```
- **剪枝条件**
当当前元素和前一个元素值相同（此处隐含这个元素的index>0），并且前一个元素还没有被使用过的时候，我们要剪枝
但是有一个注意的地方：
**对于选或不选**：只有**选**的时候才需要判断是否剪枝，如果根本不选，那么就不需要剪枝了


### 思路1：代码
```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.res = []
        check = [0 for i in range(len(nums))]
        
        self.backtrack([], 0, nums, check)
        
        return self.res
        
    def backtrack(self, sol, index, nums, check):
        if index == len(nums):
            self.res.append(sol)
            return
        
        if not (index > 0 and nums[index] == nums[index-1] and check[index-1] == 0):
            check[index] = 1
            self.backtrack(sol+[nums[index]], index+1, nums, check)
            check[index] = 0
        '''如果不选这个元素，不需要判断是否剪枝'''
        self.backtrack(sol, index+1, nums, check)
```
![image.png](https://pic.leetcode-cn.com/8c93105d127309b5c5e0570f03348a7d9c5ae154496c5445704f74df8913b48b-image.png)


### 思路2：顺序考虑，仅考虑选择的元素
![image.png](https://pic.leetcode-cn.com/c1cc4fa88962bc6e043abe08d23f87f08fdf201263e118da820a198015c3a14c-image.png)
以空集[]开始，从第一个元素开始考虑，它有三种选择，1,1',2，组成[1]，[1']，[2]
此时我们就发现，有了重复的答案，于是我们就应该剪枝：1'前面的1是相同的元素，此时发现上一个在此时是没有用过，那么就满足了我们的剪枝条件，保留[1],[2]
当第一个元素为1的时候，第二个元素可以选择的是1后面的元素1',2，组成[1,1']，[1,2]
当第二个元素为1'的时候，第二个元素可以选择2，组成[1,1',2]
结束遍历，获得组成的8个答案，这说明了有效结果是没有条件的，任何结果都是有效的，因为无效的已经被剪枝掉了


### 思路2：回溯三要素

- **有效结果**
没有条件，所有结果都是有效结果
```
self.res.append(sol)
```
- **回溯范围及答案更新**
需要循环遍历，并且是部分遍历，只考虑当前元素之后的元素们，所以需要传入一个index表示起点
！！！index仅用于表示起点，回溯的递归还是遍历的每个元素
对于答案更新，依然是累加当前元素
```
for i in range(index, len(nums)):
    if i > 0 and nums[i] == nums[i-1] and check[i-1] == 0:
        continue
    check[i] = 1
    self.backtrack(sol+[nums[i]], i+1, nums, check)
    check[i] = 0
```

- **剪枝条件**
当当前元素和前一个元素值相同（此处隐含这个元素的index>0），并且前一个元素还没有被使用过的时候，我们要剪枝
但是有一个注意的地方：
```
if i > 0 and nums[i] == nums[i-1] and check[i-1] == 0:
    continue
```

### 思路2：代码

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        check = [0 for i in range(len(nums))]
        
        self.backtrack([], 0, nums, check)
        
        return self.res
        
    def backtrack(self, sol, index, nums, check):
        self.res.append(sol)
        
        for i in range(index, len(nums)):
            if i > 0 and nums[i] == nums[i-1] and check[i-1] == 0:
                continue
            check[i] = 1
            self.backtrack(sol+[nums[i]], i+1, nums, check)
            check[i] = 0
```

### Trick：空间优化
其实在这道题还有一个小的trick可以再在上面代码的基础上做空间优化【减少额外空间的使用（但为毛提交效果不咋好。。。。）】
但这里和[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)和[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)不同的是，求子集不需要考虑**用过的元素不能再用了**，这里只需要考虑上一个相同元素是否有被使用，那么我们完全可以不用传入check数组去保存状态，我们只需要在函数的入参加一个boolean变量【0-1来表示】来保存上一个元素的使用情况：

#### 思路1：
```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.res = []
        
        self.backtrack([], 0, nums, 0)
        
        return self.res
        
    def backtrack(self, sol, index, nums, pre_used):
        if index == len(nums):
            self.res.append(sol)
            return
        
        if not (index > 0 and nums[index] == nums[index-1] and pre_used == 0):
            pre_used = 1
            self.backtrack(sol+[nums[index]], index+1, nums, pre_used)
            pre_used = 0
        self.backtrack(sol, index+1, nums, 0)
```
#### 思路2：
```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.res = []
        
        self.backtrack([], 0, nums, 0)
        
        return self.res
        
    def backtrack(self, sol, index, nums, pre_used):
        self.res.append(sol)
        
        for i in range(index, len(nums)):
            if i > 0 and nums[i] == nums[i-1] and pre_used == 0:
                continue
            pre_used = 1
            self.backtrack(sol+[nums[i]], i+1, nums, pre_used)
            pre_used = 0

```

### 注意：
考虑重复的一定要**排序**！！！

【答应了的，想要得到的，一定要付出努力，尤其是坚持，以及现在或许觉得紧张觉得害怕的，等一年后回过头来看，或许也不是什么大事情呢。】
