# 题解
## 回溯法+排序剪枝
为了对算法进行剪枝处理，首先对$candidates$排序

 1. 特判，若$candidates$为空，则返回$[]$
 2. 回溯函数$helper()$，传入参数：下一加和索引$i$，当前已加和数组$tmp$，下一目标$target$
 	* 若$target==0$，说明当前和满足条件，将当前加和数组$tmp$加入$res$，并return。
 	* **剪枝** 因为已经将$candidates$排序，所以当下一目标小于下一待加和数时，return。并且当下一待加和索引$i==n$时，return。为了**防止数组越界**，将条件$i==n$放在$target<candidates[i]$之前，进行截断。
 	* 因为可重复调用元素，所以$helper(i,tmp+[candidates[i],target-candidates[i]])$，继续重复调用自身。
 	* 调用数组中下一元素，寻找新答案。$helper(i+1,tmp,target])$。
 
 3. 执行$helper(0,[],target)$，并返回$res$


### 复杂度分析
 - 时间复杂度：$O\left(2^{n}\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if(not candidates):
            return []
        n=len(candidates)
        res=[]
        candidates.sort()
        def helper(i,tmp,target):
            if(target==0):
                res.append(tmp)
                return
            if(i==n or target<candidates[i]):
                return
            helper(i,tmp+[candidates[i]],target-candidates[i])
            helper(i+1,tmp,target)
        helper(0,[],target)
        return res
```
**剪枝效果，有点好！**
![剪枝后](https://pic.leetcode-cn.com/53d50f967c3761682266b8e01e561bc9cfe8c7e867d4077b4320dea2015560fb.png)
![未剪枝](https://pic.leetcode-cn.com/f0b202649e08275b054a69b4c31820fca444dcb2dd2d12ff7c3f45a7c0bbd54b.png)