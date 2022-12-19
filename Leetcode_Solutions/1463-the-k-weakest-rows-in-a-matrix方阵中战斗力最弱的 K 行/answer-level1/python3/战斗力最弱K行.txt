一、算法思想
1.计算方针中各行元素的和，将每行的和与行号以元组形式保存到存储每行战斗力的数组中。
2.对存储每行战斗力的数组进行排序。
3.依次返回排序后数组前k个元素中的各行号值。
二、算法实现
```
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        force = []
        for i, row in enumerate(mat):
            force.append((sum(row), i))
        force.sort()
        res = []
        for j in range(k):
            res.append(force[j][1])
        return res
```
三、复杂度分析
1.时间复杂度：计算各行元素战斗力的时间复杂度为O(M*N)，python中对数组进行排序的蒂姆排序算法时间复杂度为O(MlogM)，所以总的时间复杂度为O(max(M*N,MlogM))。
2.空间复杂度：force数组的空间复杂度为O(M)，对其进行排序所用蒂姆排序算法的空间复杂度为O(M)，所以该算法的空间复杂度为O(M)。

