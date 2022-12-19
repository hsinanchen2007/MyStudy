### 解题思路
此问题最清晰的方式就是递归回溯和动态规划，由于我看大多数人都用的回溯法，所以我就使用了动态规划。

（1）基本流程
设字典num，num[i]表示target等于i时的组合总和
当i比candidates中最小值都小的时候num[i]为空
num[j] = num[j-x]的组合+[x]，x为candidate中的元素。
（2）去除多余步骤
根据分析可知当j-x<i时且j!=x时，表示num[j-x]为空，则直接跳过。
当j=x时直接将[x]加入即可
（3）去重
因为过程中会有一些相同的组合出现，比如i = 5时，[2,3]与[3,2]相同，所以需要去掉重复元素
方法：排序后判断。


### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if candidates == []: return []
        num = {}

        for i in range(min(candidates)):num[i] = []
        if target<i+1:return num[target]

        for j in range(i+1,target+1):
            num[j] = []
            for x in candidates:
                if x==j:num[j].append([x])
                if x>=j-i:continue
                for nu in num[j-x]:
                    n = [x]
                    n.extend(nu)
                    n.sort()
                    if n not in num[j]:
                        num[j].append(n)

        
        return num[target]

```