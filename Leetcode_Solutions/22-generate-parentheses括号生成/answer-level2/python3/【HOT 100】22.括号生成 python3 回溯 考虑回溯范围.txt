### 解题思路
- **相似题型**
- **回溯三要素**
- **代码**

### 相似题型
回溯大礼包：
[46.全排列](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)
[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)
[78.子集](https://leetcode-cn.com/problems/subsets/solution/hot-100-78zi-ji-python3-hui-su-liang-chong-jie-ti-/)
[90.子集II](https://leetcode-cn.com/problems/subsets-ii/solution/hot-100-90zi-ji-ii-python3-hui-su-kao-lu-zhong-fu-/)

### 回溯三要素
这道题的思路主要是如何去生成括号：
![image.png](https://pic.leetcode-cn.com/5cc2fcb6d38d1f28dd6f2ab08267100b7462dcd455517edfce1ed4a1287cb1f3-image.png)

`n`是括号对数，`left`是已使用的左括号个数，`right`是已使用的右括号个数
很明显能够之后，有效括号的第一个元素永远只能是`(`，并且左括号和右括号必须个数相等，`并且匹配:这个匹配就是当左括号小于n的时候，还能往左括号方向回溯，当右括号小于左括号的时候，还能往右括号方向回溯`

- **有效结果**
当`右括号的个数==n`的时候，说明结束了，或者当`总括号个数==2*n`的时候，就说明找到了答案
```
if right == n:  # if (left+right) == 2*n
    self.res.append(sol)
    return
```

- **回溯范围及答案更新**
1.当左括号的个数小于n的时候，还能添加左括号
2.当右括号的个数小于左括号的个数时，才能添加右括号
```
if left < n:
    self.backtrack(sol+'(', left+1, right, n)
if right < left:
    self.backtrack(sol+')', left, right+1, n)
```

- **剪枝条件**
不需要剪枝，已经在回溯范围处限定了回溯的下一层

### 代码

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        
        self.backtrack('', 0, 0, n)
        
        return self.res
        
        
    def backtrack(self, sol, left, right, n):
        if right == n:
            self.res.append(sol)
            return
        
        if left < n:
            self.backtrack(sol+'(', left+1, right, n)
        if right < left:
            self.backtrack(sol+')', left, right+1, n)
            
```
![image.png](https://pic.leetcode-cn.com/b7da2c243594ac0630c5714be38151266bcae97171f8deb4ee900b7a1182daa5-image.png)
