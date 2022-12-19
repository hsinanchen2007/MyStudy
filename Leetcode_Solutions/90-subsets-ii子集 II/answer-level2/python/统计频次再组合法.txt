提供一个不用去重也不用排序的思路，

先统计每个数字的频次，

之后再根据每个数字的频次来组合，如 [1，2，2，3，3，3]

得到字典｛1:1,2:2,3:3｝之后，

直接按个数组合就能得到结果也能避免重合。即0个数字的子集为1种，1个数字的子集为3种，2个数字的子集……6个数字的子集就能得到所有结果

以下代码基于上述思路，但用了一点小trick实现，时间85%，空间95%左右

```python
# 刚开始我们只有空集一个答案，循环所有可能的数字，每次循环我们对当前答案的每一种情况考虑加入从1到上限次该数字并更新答案即可
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        dic = {}
        for i in nums:
            dic[i] = dic.get(i, 0) + 1
        res = [[]]
        for i, v in dic.items():
            temp = res.copy()
            for j in res:
                temp.extend(j+[i]*(k+1) for k in range(v))
            res = temp
        return res
```
