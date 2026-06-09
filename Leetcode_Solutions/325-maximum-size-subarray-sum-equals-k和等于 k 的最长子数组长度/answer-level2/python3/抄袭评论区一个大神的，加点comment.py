### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:

        dic = {0:-1}
        cur_prefix = 0
        res_len = 0
        for idx, val in enumerate(nums):
            cur_prefix += val
            # cur 倒出 k，说明，i和idx之间的窗口为k，这点不是k-cur
            if (cur_prefix-k) in dic:
                res_len = max(res_len, idx-dic[cur_prefix-k])
            # 记录最前面的位置
            if cur_prefix not in dic:
                dic[cur_prefix] = idx

        return res_len

            

```