# 题解
和39不同的是，$candidates$中每个数字只能使用一次
同样，为了回溯的剪枝，首先对$candidates$进行排序
## 回溯法+排序剪枝
 1. 特判，若$candidates$为空，则返回$[]$
 2. 回溯函数$helper()$，传入参数：下一加和索引$i$，当前已加和数组$tmp$，下一目标$target$
 	* 若$target==0$，说明当前和满足条件，将当前加和数组$tmp$加入$res$，并return。
 	* **剪枝** 因为已经将$candidates$排序，所以当下一目标小于下一待加和数时，return。并且当下一待加和索引$i==n$时，return。为了**防止数组越界**，将条件$i==n$放在$target<candidates[i]$之前，进行截断。
 	* 对于$j$遍历区间$[i,n)$，根据条件$j>i and candidates[j]==candidates[j-1]$（为了**防止数组越界**，首先保证$j>i$，判断是否和上一元素相等），分为以下两种情况：
 		+ 若满足条件$j>i and candidates[j]==candidates[j-1]$，则跳过，避免出现重复解，同时也进行了剪枝。
 		+ 否则，执行$helper(j+1,tmp+[candidates[j]],target-candidates[j])$
 
 3. 执行$helper(0,[],target)$，并返回$res$



### 复杂度分析
 - 时间复杂度：$O\left(n!\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if(not candidates):
            return []
        n=len(candidates)
        candidates.sort()
        res=[]
        def helper(i,tmp,target):
            print(i,tmp,target)
            if(target==0):
                res.append(tmp)
                return
            if(i==n or target<candidates[i]):
                return
            for j in range(i,n):
                if(j>i and candidates[j]==candidates[j-1]):
                    continue
                helper(j+1,tmp+[candidates[j]],target-candidates[j])
        helper(0,[],target)
        return res
```