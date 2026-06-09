### 解题思路
- **相似题型**
- **两种解题思路**
- **回溯三要素**
- **代码**

### 相似题型
**回溯一家亲**，还是经典的排列组合，当然是这几个小伙伴啦：
[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)
[47.全排列 II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)

### 两种解题思路
#### 1.全部考虑，选或不选
拿到这个题，很熟悉的就是[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)，可以按一贯的考虑回溯问题的思路来考虑这道题：
对于`[1,2,3]`，我们该如何枚举它的子集呢，它的组合个数应该是`2**5`个：1选或不选，有两种情况，2选或不选，有两种情况，3选或不选，有两种情况，那么总共就是`2\*2\*2=8`种情况：

![image.png](https://pic.leetcode-cn.com/4dff0bf6af1f4fd4b4bd8b42ee26a83ec832ac56998134d2eeb034a573861221-image.png)

针对这个分析，依然灵魂画手的show time：
绿色的为最终答案：
![image.png](https://pic.leetcode-cn.com/449e267e9ddb8d409ae46fdddd5a7e5f1cb04604c64526e0ecfdfacf1558d9c3-image.png)

看起来我们并不需要遍历，而是需要每一层都考虑一下当前元素的index对应的值，我们是要还是不要，于是又是**小trick**：`我们不需要用遍历，但是又要对不同index进行判断，那么我们就传入一个index变量进去，每次改变index就可以了，用于指向每个元素。`

把比较棘手的考虑了，我们就可以整体考虑回溯三要素了。

#### 回溯三要素 
1. **有效结果**
   当指向元素的`index==len(nums)`的时候，就说明这一次的搜索结束了
```
if index == len(nums):
    self.res.append(sol)
    return
```
2. **回溯范围及答案更新**
   不需要循环遍历，而只需要用一个index指向每一次的元素，`下一层更新index = index+1`
   对于答案更新，我们需要`考虑选或不选当前答案`，保存当前index指向的元素
```
self.backtrack(sol+[nums[index]], index+1, nums)  
self.backtrack(sol, index+1, nums)
```
3. **剪枝条件**
   不需要剪枝

#### 代码
**画图+回溯三要素=代码很简单**

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        self.backtrack([], 0, nums)
        return self.res
        
    def backtrack(self, sol, index, nums):
        if index == len(nums):
            self.res.append(sol)
            return
        
        self.backtrack(sol+[nums[index]], index+1, nums)
        self.backtrack(sol, index+1, nums)
```
![image.png](https://pic.leetcode-cn.com/91d015f8e2540bf8efd87d11ab63b15eaedfa4d212d7513fa89599af413b2958-image.png)
<br/>

#### 2.顺序考虑，仅考虑选择的元素
除了上面的思路，还有一种需要遍历思考的思路，那就是**顺序考虑，仅考虑选择的元素**：
以空集`[]`开始，从第一个元素开始考虑，它有三种选择，1,2,3，组成`[1]，[2]，[3]`
当第一个元素为1的时候，第二个元素可以选择的是1后面的元素2,3，组成`[1,2]，[1,3]`
当第二个元素为2的时候，此时[1,2]，第三个元素可以选择3，组成`[1,2,3]`
当第一个元素为2的时候，第二个元素可以选择3，组成`[2,3]`
结束遍历，获得组成的8个答案，这说明了`有效结果是没有条件的，任何结果都是有效的`
![image.png](https://pic.leetcode-cn.com/56781b4fdb0c2183abe39499f02eea6dc92cbf81355d0d96c3a4de81fdcf9bdb-image.png)

那么需要遍历吗，回溯的范围是什么呢？
根据图，我们发现还是需要遍历的，并且还是部分遍历而不是全部遍历，因为我们只需要遍历当前元素之后的元素们，又是小trtrick时间：部分遍历的时候，需要传入一个index的起点，用于保证是部分在循环：

![image.png](https://pic.leetcode-cn.com/59b9bd2ce540b83547975282f1670adc87d7b8566406b99af5dfcd9b61aadc84-image.png)


整体思路有了概念，那么可以总结回溯三要素了

#### 回溯三要素 
1. **有效结果**
   没有条件，所有结果都是有效结果
```
self.res.append(sol)
```
2. **回溯范围及答案更新**
   需要循环遍历，并且是部分遍历，只考虑当前元素之后的元素们，所以需要传入一个index表示起点
   `！！！index仅用于表示起点，回溯的递归还是遍历的每个元素`
   对于答案更新，依然是累加当前元素
```python
for i in range(index, len(nums)):
    self.backtrack(sol+[nums[i]], i+1, nums) 
    ## 一定要注意这里的递归传入是i+1，index只是当前起点，不代表下一层范围
```
3. **剪枝条件**
   不需要剪枝

### 代码
思路清晰，写代码就很顺畅
`积累+总结`

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        self.backtrack([], 0, nums)
        
        return self.res
        
    def backtrack(self, sol, index, nums):
        self.res.append(sol)
        
        for i in range(index, len(nums)):
            self.backtrack(sol+[nums[i]], i+1, nums)

```
![image.png](https://pic.leetcode-cn.com/891e80bea309174459342da09de1cc8865b26b75e32d64c8b78a73b3220c74c5-image.png)
