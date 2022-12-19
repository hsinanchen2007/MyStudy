## 解题思路

今天开始（2020/1/10），写题解先写大纲，然后再看一遍标记重点，看是不是写得能让人看着不烦能看下去，以及自己要整理笔记记录
【还是下意识写了2019，却惊觉已经到了2020年，那么上一年的自己到底学到了什么，输出了什么呢，2020继续重新做人】

- 相似题型
- 考虑重复
- 回溯问题三个考虑方面
- 附：两种不同剪枝条件的区别
- 代码
<br />

### 相似题型
[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)

看到**全排列**，或者**枚举全部解**，等类似的**搜索枚举类型题**，基本就是**回溯**没跑了。
因为`回溯就是类似枚举的搜索尝试过程，主要是在搜索尝试过程中寻找问题的解，当发现已不满足求解条件时，就“回溯”返回，尝试别的路径`。

回溯主要的考虑的**三要素**已经在[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)写过了，但是这道题有了一点改变，那么就是列表里面有重复数字，全排列的结果，相同答案只算一种，那么我们就要优先考虑重复，再思考**三要素**，定下我们思路和代码的基调。
【**flag**：上一篇写得有点乱，之后再去整理，顺便汇总回溯题，emmm好像上一篇也有一个flag（逃。。】

### 考虑重复
重复即为：存在相同数字，比如[1,2,2']，那么`答案[1,2,2']和[1,2',2]就其实是一样的`，在保存结果的时候，我们只选择其一，但是这不是字符串，在保存结果的时候再去判断是否答案里已经保存了这一种情况会比较麻烦，那么我们能不能在生成答案的过程中就将其**剪枝**（类比用过的数字就不考虑），这样根本就不会生成重复的答案了。

我们希望的是，如果发现数字重复了，当前的就不考虑了，比如[1,2,2']存在之后，当遇到[1]遇到2'，发现和2重复了，我就直接剪枝，不考虑之后的所有的情况，因为：
![image.png](https://pic.leetcode-cn.com/b99f92354583b0dbf289b180da5527ea5d71b26ca81f83229d7d96ab96c8b6ff-image.png)
两个相同数字，我可以：
1. 两个都选
2. 两个都不选
3. 但是如果只选一个，那么选哪一个都可以，因为和选择另一个是相同情况，**所以只有这种情况我们需要剪枝**
<br />
#### 又到了小trick时间：
**考虑重复元素一定要优先排序**，将重复的都放在一起，便于找到重复元素和剪枝！！！
推广至 --> **如果涉及考虑重复元素，或者大小比较的情况，对列表排序是一个不错的选择**

好了，我们知道要排序，重复元素要剪枝，那么该如何剪枝呢？
首先我们得使用第一个元素，因为这时候是第一次使用，还没有重复，并且所有情况都回溯搜索答案，除了用过的元素不再使用，其余不做剪枝，直到我们遇到第一个重复元素，我们才要考虑剪枝，但是考虑剪枝的时候还要考虑跟它重复的元素有没有被用过：

![image.png](https://pic.leetcode-cn.com/411c88e56c5538a787b4bd4c86d433f00a461d93c0af8ca3a74d7bed41055c34-image.png)

如果前一个重复元素没有使用过，那么在当前重复元素下一层的可选项中一定会存在，也就是绿色部分
那么一定会重复，即出现 `2 X = X 2'` 的情况`（X为不选）`
也就是2和2' 以及 2'和2一定会重复，则整体剪枝，且是提前剪枝，在红色选择处就剪枝

那么这部分剪枝的条件即为：**和前一个元素值相同（此处隐含这个元素的index>0），并且前一个元素还没有被使用过**


### 回溯问题三要素

把和[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)的区别--重复，考虑了之后，这道题就是和我们之前写过的思考过程一样了，依然是回到老三样：

1. **有效结果**
   仍然是当前结果的长度==列表的长度，即为找到了一个有效结果
   
```
if len(sol) == len(nums):
            self.res.append(sol)
```
2. **回溯范围及答案更新**
   - 仍然是全部遍历，因为每一层都要考虑全部元素
   - 答案更新仍然是在修改check之后回溯内部累加更新sol
    
```
for i in range(len(nums)):
    check[i] = 1
    self.backtrack(sol+[nums[i]], nums, check)
    check[i] = 0
```
3.  **剪枝条件**
   在之前的**剪枝条件1**：用过的元素不能再使用之外，又添加了一个新的剪枝条件，也就是我们考虑重复部分思考的结果，于是**剪枝条件2**：当当前元素和前一个元素值相同（此处隐含这个元素的index>0），并且前一个元素还没有被使用过的时候，我们要剪枝
```
if check[i] == 1:
    continue
if i > 0 and nums[i] == nums[i-1] and check[i-1] == 0:
    continue
```

### 代码
考虑完三要素就可以写代码啦！

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.res = []
        check = [0 for i in range(len(nums))]
        
        self.backtrack([], nums, check)
        return self.res
        
    def backtrack(self, sol, nums, check):
        if len(sol) == len(nums):
            self.res.append(sol)
            return
        
        for i in range(len(nums)):
            if check[i] == 1:
                continue
            if i > 0 and nums[i] == nums[i-1] and check[i-1] == 0:
                continue
            check[i] = 1
            self.backtrack(sol+[nums[i]], nums, check)
            check[i] = 0
```

![image.png](https://pic.leetcode-cn.com/95879d993505786c00bc03ecb1fc928fcf1fd25d0726aef0a0b23ea37fa7c4ef-image.png)


### 附：两种不同剪枝条件的区别

在考虑重复及剪枝条件的时候，我们考虑的是：当当前元素和前一个元素值相同（此处隐含这个元素的index>0），并且前一个元素还没有被使用过的时候，我们要剪枝
但实际，如果条件设为：并且前一个元素被使用过，我们要剪枝，其实也是可以的：
```
if i > 0 and nums[i] == nums[i-1] and check[i-1] == 1:
    continue
```
但是这两种有什么区别，又该如何选择呢？
**主要的区别还是在于在那个阶段剪枝，以及重复元素中选择哪一个。**
**`结论：选择check[i-1] == 0效率要高于check[i-1] == 1`**

看了很多解释，但是还是一定要自己画图理解！回溯的图真的是天助，画图能很好理解递归：
#### 1. if i > 0 and nums[i] == nums[i-1] and check[i-1] == 0
灰色为剪枝部分，蓝色为答案部分：
![image.png](https://pic.leetcode-cn.com/ddb3425584f42015765c51bd5d85589842b74be2040a5ca8177283d060cf5dc9-image.png)

#### 2. if i > 0 and nums[i] == nums[i-1] and check[i-1] == 1
灰色为剪枝部分，蓝色为答案部分：
![image.png](https://pic.leetcode-cn.com/b9129a3a086ad120ccb897cce3cdb085cc71b2e4e9a1441bc73644a5c5c65480-image.png)

能够明显发现第一种能够提前剪枝，减少计算步骤和搜索次数，并且第一种选择了重复元素的第一个，而第二种选择了重复元素的最后一个，虽然答案都相同，我们成年人当然是要选效率更高一些的那一种对吧~


### 总结
哈哈，其实只是为了一个ending~
那就要为了自己选择的路努力前进吧！



