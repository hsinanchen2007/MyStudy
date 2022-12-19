**思路：**

先把数组`arr1`分成两部分，一部分是存在于`arr2`中的数，另一部分是不存在于`arr2`中的数。对于第二部分，很容易，我们可以直接排序，放在第一部分的后面。对于第一部分的数，要按照`arr2`中的数字顺序排序，那么我们其实可以统计`arr2`中的数在这部分出现了多少次，然后遍历`arr2`的同时，在答案数组中加入相同频次的这个数字即可。


**代码：**
```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        not_exist = []
        exist = []
        s = set(arr2)
        ans = []
        for a in arr1:
            if a in s:
                exist.append(a)
            else:
                not_exist.append(a)
        cnt = collections.Counter(exist)
        for a in arr2:
            ans += [a] * cnt[a]
        return ans + sorted(not_exist)
```