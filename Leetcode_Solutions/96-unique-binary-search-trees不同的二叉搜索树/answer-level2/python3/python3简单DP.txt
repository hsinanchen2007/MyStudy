### 解题思路
python3简单DP

### 代码

```python3
class Solution:
    def numTrees(self, n: int) -> int:
        dp_arr = [1, 1, 2]
        if n < 3:
            return dp_arr[n]

        for index in range(3, n+1):
            cur_count = 0
            for cur_index in range(0, index):
                cur_count += dp_arr[cur_index] * dp_arr[index - 1-cur_index]
            dp_arr.append(cur_count)

        return dp_arr[-1]

```