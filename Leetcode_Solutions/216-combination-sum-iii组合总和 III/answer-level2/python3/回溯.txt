### 解题思路
回溯函数backtrance(i, cur_sum, k, arr)
i表示当前起点，cur_sum表示当前累加的结果，k表示还需要k个数，arr表示当前已经选择的数。
for循环，选择一个数，然后k减1，递归这个数右边
当k等于0，或者i大于9的时候结束递归

### 代码

```python3
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.ans = []
        def backtrace(i, cur_sum, k, arr):
            if k == 0 and cur_sum == n:
                self.ans.append(arr)
            if k == 0 or i > 9:
                return
            
            for num in range(i, 10):
                backtrace(num+1, cur_sum+num, k-1, arr+[num])
        backtrace(1, 0, k, [])
        return self.ans
            


```