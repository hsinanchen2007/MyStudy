### 解题思路
执行用时 :44 ms, 在所有 Python3 提交中击败了94.56%的用户
看到这个94.56%才敢贴的

就是用字典和列表存储下数字的出现次数，然后比较下能不能整除从2到最小的出现次数


### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        dic = {}
        for num in deck:
            if num in dic:
                dic[num] += 1
            else:
                dic[num] = 1
        times = [value for key, value in dic.items()]
        if min(times) < 2:
            return False
        for X in range(2, min(times)+1):
            success = 1
            for num in times:
                if num % X != 0:
                    success = 0
            if success == 1:
                return True
        return False
```