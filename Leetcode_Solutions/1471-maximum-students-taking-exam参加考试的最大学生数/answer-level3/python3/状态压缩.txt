### 解题思路
- 按行来看，每行一共可能有 $2^8$ 种状态；这个行状态与上一行状态是因果(causal)的关系，可以递推；
- 状态：`d[irow][state]` 到`irow`为止，`state`状态最多可以坐几个人；
- 转移方程 `d[irow][state] = max_{prev_state}(d[irow][state], d[irow-1][prev_state]`
- 注意判断合法状态，以及合法转移；

### 代码

```python
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        res = 0
        self.n_row = len(seats)
        self.n_col = len(seats[0])
        valid = []

        # init the valid states
        for irow in seats:
            tmp = 0
            for icol in irow:
                if icol == '.':
                    tmp = (tmp << 1) + 1
                else:
                    tmp = tmp << 1
            valid.append(tmp)
        
        def count_bits(inp):
            cnt = 0
            while(inp):
                cnt += inp % 2
                inp = inp >> 1
            return cnt
        
        d = [[0] * 2**self.n_col for ind in range(self.n_row+1)]

        for ir in range(1, self.n_row+1):
            for mask in range(2**self.n_col):
                if mask & valid[ir-1] == mask and not (mask & (mask>>1)):
                    for pmask in range(2**self.n_col):
                        if not ((pmask >>1) & mask) and not ((mask >>1) & pmask):
                            d[ir][mask] = max(d[ir][mask], d[ir-1][pmask] + count_bits(mask))

        res = max(d[self.n_row])

        return res
```