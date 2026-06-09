这应该是最标准的DP了
```
class Solution:
    def waysToStep(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        elif n == 3:
            return 4
        else:
            ans_list = [1,2,4]
            for i in range(3, n):
                ans_list.append((ans_list[i-1] + ans_list[i-2] + ans_list[i-3]) % 1000000007)
            return ans_list[-1]
```
