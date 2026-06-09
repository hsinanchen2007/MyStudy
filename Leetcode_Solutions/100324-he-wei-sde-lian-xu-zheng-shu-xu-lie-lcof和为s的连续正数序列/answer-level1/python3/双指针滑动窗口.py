### 解题思路
此处撰写解题思路
双指针 注意事项在备注中
### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        l = 1
        r = 1
        sum = 0
        res = []
        while l <= target//2:###//2以满足至少含两个数
            if sum < target:
                sum += r###应该先把r加进sum 而不是先r+1
                r += 1
            elif sum>target:
                sum -= l
                l += 1
            else:
                res.append(list(range(l,r)))
                sum -= l
                l += 1
        return res

```