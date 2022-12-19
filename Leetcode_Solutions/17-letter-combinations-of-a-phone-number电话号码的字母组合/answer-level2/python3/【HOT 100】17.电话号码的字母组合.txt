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
[40.组合总和II](https://leetcode-cn.com/problems/combination-sum-ii/solution/hot-100-40zu-he-zong-he-ii-python3-hui-su-by-sammy/)

### 回溯三要素
这一题其实和相似题型们都有一点区别，我们还是画图来看，当`digits='29'`时：

![image.png](https://pic.leetcode-cn.com/2b57713c279e3b837f845ca24d24acf4a0c04a2e54212e94dce49eb306f1844a-image.png)

我们能够发现，其实就是**第一层的每个元素都和第二层的每个元素相结合**，引申就是**上一层的元素会和当前层的每个元素相结合**，所以上一层的元素只会和当前层的每个元素结合一次，不会遍历去结合每个元素及之后的，这样考虑起来就比较简单，不容易混乱（主要是我曾混乱过。。。）
于是得出：**每一层只考虑当层，不能当层考虑循环遍历**

那么我们就需要一个索引`depth`来表示当前层，而且很容易发现，当`depth==len(digits)`的时候，组合结束，获得我们的有效结果，然后每一次回溯，我们不再是考虑这个元素之后的元素们，而是我们需要考虑当前层之后的下一层，也就是`depth+1`时的情况

基于此，我们就很容易得出**回溯三要素**：
- **有效结果**
当`depth==len(digits)`的时候，组合结束，获得我们的有效结果
```
if depth==len(digits):
    self.res.append(sol)
    return
```

- **回溯范围及答案更新**
我们需要考虑当前层之后的下一层，也就是`depth+1`时的情况，并将**上一层的元素会和当前层的每个元素相结合**，这里需要先获得当前层的元素，也当前层的数字对应的键盘字母：
```
self.d = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
num = digits[depth]
s = self.d[num]
for i in s:
    self.backtrack(sol+i, depth+1, digits)
```

- **剪枝条件**
不需要剪枝，已经在回溯范围内考虑过了


### 代码
考虑好了就可以很easy的写代码了，但是一定要注意：**是每一层的更新，而不是元素index的更新**

```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        self.res = []
        self.d = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        
        self.backtrack('', 0, digits)
        
        return self.res
        
        
    def backtrack(self, sol, depth, digits):
        if depth == len(digits):
            self.res.append(sol)
            return
        
        num = digits[depth]
        s = self.d[num]
        
        for i in s:
            self.backtrack(sol+i, depth+1, digits)
```
![image.png](https://pic.leetcode-cn.com/46d9175133d3bf1900ca5ff73b089c8acd08ba257dcd5b5ee83bbacef7382387-image.png)
