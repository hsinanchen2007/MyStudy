
# Leetcode 47. 全排列 II

## 问题描述

[47. 全排列 II - 力扣（LeetCode）](https://leetcode-cn.com/problems/permutations-ii/)


## 算法

### 解法一：回溯法

好多题解都是用一个list表记录一个元素是否被选择过。**但是这道题既然有重复元素，那么用一个list来记录会比较复杂，更加合适的是用一个hash表来记录**。其中键是 nums 中的元素，对应的值是键在nums中出现的次数。

如 [1,1,2]，对应的 hash 表命名为 candidates，则初始的 candidates = {1:2, 2:1}
如果元素 1 在 nums 中出现了 2 次，那么在构成解的时候 1 这个元素当然就可以选择2次

#### 递归树

据说写回溯题都需要画递归树？递归树长这个样子

![image.png](https://pic.leetcode-cn.com/afc76ea6904481938cd8282512fad17e2c7828c2713cc692ddba2422769400bc-image.png)

#### 模板

这里参考了大佬的模板 - [回溯算法详解 - 全排列 - 力扣（LeetCode）](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/)

```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```     
        
#### 三要素

根据递归树得到下面三个要素，这里参考了又一位大佬的题解  [【HOT 100】46.全排列 Python3 回溯 step by step理解回溯 要画图！ - 全排列 - 力扣（LeetCode）](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)

1. 结束条件

由于是要生成排列，所以所有元素都需要添加到 path 中，因此结束条件当然是 path 中的元素为 nums 中的所有元素

```
 if len(path) == len(nums):
    result.append(path[:])
    return
```

2. 递归

candidates 中对应的值是 0 说明不能选择，因此添加一个 if 判断，只有 candidates 中对应的值不是 0 才能继续递归

```
for c in candidates:
    if candidates[c] > 0:
        # 做选择
        candidates[c] -= 1
        dfs(path+[c])
        # 撤销选择
        candidates[c] += 1
```

3. 剪枝：不需要剪枝

#### 实现

##### 解法一python


截图装个b：
![image.png](https://pic.leetcode-cn.com/e91697ff292eaf139ebc1872bbfba21d4dab96a9bc777b92254e0f18c45017e5-image.png)

```
from collections import Counter
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = []
        candidates = Counter(nums)

        def dfs(path):
            if len(path) == len(nums):
                result.append(path[:])
                return
            for c in candidates:
                if candidates[c] > 0:
                    candidates[c] -= 1
                    dfs(path+[c])
                    candidates[c] += 1
        dfs([])
        return result
```

# References

- [【HOT 100】46.全排列 Python3 回溯 step by step理解回溯 要画图！ - 全排列 - 力扣（LeetCode）](https://leetcode-cn.com/problems/permutations/solution/hot-100-46quan-pai-lie-python3-hui-su-step-by-step/)

- [回溯算法详解 - 全排列 - 力扣（LeetCode）](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/)