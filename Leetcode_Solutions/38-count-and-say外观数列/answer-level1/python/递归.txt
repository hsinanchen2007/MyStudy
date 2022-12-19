### 解题思路
时间复杂度：O（n）
空间复杂度：O（1）

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        res_str = ""
        from collections import defaultdict
        last_result = self.countAndSay(n-1)
        key = last_result[0]
        default_dict = defaultdict(int)
        for i in range(len(last_result)):
            if last_result[i] == key:
                default_dict[key] += 1
            else:
                res_str += str(default_dict[key]) + key
                default_dict.clear()
                key = last_result[i]
                default_dict[key] += 1
        res_str += str(default_dict[key]) + key
        return res_str


```