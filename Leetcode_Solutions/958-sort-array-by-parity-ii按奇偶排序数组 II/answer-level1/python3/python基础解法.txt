解题思路：创建一个空列表，遍历数组，将偶数放到ans[0], ans[2]这样，奇数放在ans[1], ans[3]这样。还有一种方式是碰到奇偶不一致的情况下进行交换。
第一种情况的代码：
```
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        ans = [None] * len(A)
        ans[::2] = (x for x in A if x % 2 == 0)
        ans[1::2] = (x for x in A if x % 2 == 1)
        return ans
```
