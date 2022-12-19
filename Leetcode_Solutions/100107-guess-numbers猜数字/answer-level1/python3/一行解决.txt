```
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        return sum(map(int.__eq__,guess,answer))
```
执行用时 : 44 ms , 在所有 Python3 提交中击败了 100.00% 的用户 内存消耗 : 13.7 MB , 在所有 Python3 提交中击败了 100.00% 的用户
简单到怀疑人生，终于我也可以写题解了
