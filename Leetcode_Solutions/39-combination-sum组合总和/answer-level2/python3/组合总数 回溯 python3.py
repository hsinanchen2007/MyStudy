### 解题思路
我们首先将输入列表中大于目标值的值删掉，因为结果中一定不包含大于目标值的值
定义一个method函数来执行回溯算法
在method函数前定义res来存储返回结果，定义temp列表来存储回溯中的当前路径中的数的集合
1. 在回溯过程中，如果当前路径中数字总和小于目标值，则继续回溯
2. 如果当前路径中数字总和等于目标值，则在结果中加入当前数字集合，此处将该数字集合排序以去重，避免res中出现重复元素，并返回至上一步执行
3. 如果当前路径中数字总和大于目标值，则直接返回上一步执行

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        temp = []
        for i in candidates:
            if i > target: candidates.remove(i)
        def method(s, l, t):
            for i in l:
                if s+i<t:
                    temp.append(i)
                    method(s+i, l, t)
                    temp.pop(-1)
                elif s+i==t:
                    temp.append(i)
                    if sorted(temp) not in res:
                        res.append(sorted(temp))
                    temp.pop(-1)
                    return
                else:
                    return
        method(0, sorted(candidates), target)
        return res
                    
```