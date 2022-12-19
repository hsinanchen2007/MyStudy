### 解题思路
说来惭愧，我之前也看过回溯算法的相关内容，但是我还是分不清什么是回溯算法，所以我统称为递归，不过我看了别人用“回溯算法”写的和我写的好像也差不多，那我这应该也是回溯算法。
思路：
（1）快排；
（2）递归。关键是这个递推式怎么写，对于排序过后的数组，可以设置一指针，对于指针指向的数值可以选择加入到方案中或者不加入。

### 代码

```python
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def quick_sort(candidates, left, right):
            if right - left <= 1:
                return 
            temp = candidates[left]
            p, q = left, right
            while p < q:
                while p < q and candidates[q] > temp:
                    q -= 1
                if p < q:
                    candidates[p] = candidates[q]
                    p += 1
                while p < q and candidates[p] < temp:
                    p += 1
                if p < q:
                    candidates[q] = candidates[p]
                    q -= 1
            candidates[p] = temp
            quick_sort(candidates, left, p - 1)
            quick_sort(candidates, p + 1, right)

        quick_sort(candidates, 0, len(candidates) - 1)

        def get_res(ind, sum, temp):
            if sum == target:
                res.append(temp)
                return 
            elif sum > target or ind == len(candidates):
                return 
            get_res(ind, sum + candidates[ind], temp + [candidates[ind]])
            get_res(ind + 1, sum, temp)

        res = []
        get_res(0, 0, [])
        return res
```