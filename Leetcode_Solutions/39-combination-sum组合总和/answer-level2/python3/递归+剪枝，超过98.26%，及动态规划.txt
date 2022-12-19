```
class Solution:
    def combinationSum(self, candidates: list, target: int) -> list:
        return self.search(sorted(candidates), target)      # 先排序，再递归

    def search(self, sorted_list: list, target: int) -> list:
        res = []
        for i, v in enumerate(sorted_list):
            if target > v:
                for lis in self.search(sorted_list[i:], target-v):  # 禁止使用小于当前的数字进行组合尝试
                    res.append([v]+lis)
            else:
                if target == v: res.append([v])
                break   # 当出现数字大于等于当前目标值时停止
        return res
```
代码较简单，先贴上来，主要有三点
1. 先将给定数组排序，再使用递归搜索
2. 当出现第一个大于或等于当前目标值的数字时就可以停止迭代了
3. 还有一个是使用sorted_list[i:]进行更深层的递归以保证所有结果都是有序的，这样就不会出现[2,3,2]这种重复结果了

还有一个实现是使用动态规划方法，天然没有重复
```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        a = [[[]]] + [[] for i in range(target)]
        for i in candidates:
            for j, v in enumerate(a[i:]):
                v.extend([lis+[i] for lis in a[j]])
        return a[-1]
```
