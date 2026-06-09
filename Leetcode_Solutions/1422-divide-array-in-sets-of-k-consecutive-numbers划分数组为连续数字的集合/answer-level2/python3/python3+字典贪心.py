### 解题思路
先用一个字典统计每个数字的个数，再对字典的键进行排序，然后依次选择k个连续数，看这k个数是否都在字典中，以及每一个数出现的次数是不是都大于起始数的个数，如果不是，直接返回false，如果是，这k个数的个数分别减去起始数的个数，最后在判断一下边界就行

### 代码

```python3
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        d = {}
        for i in range(len(nums)):
            if nums[i] in d:
                d[nums[i]] += 1
            else:
                d[nums[i]] = 1
        res = sorted(d.keys())
        if len(res) < k:
            return False
        for i in range(len(res)-k+1):
            if d[res[i]] == 0:
                continue
            for j in range(1,k):
                if res[i] + j not in d or d.get(res[i] + j,0) < d.get(res[i],0):
                    return False
                else:
                    d[res[i] + j] -= d[res[i]]
            d[res[i]] = 0
        if sum(d.values()) != 0:return False
        return True
```