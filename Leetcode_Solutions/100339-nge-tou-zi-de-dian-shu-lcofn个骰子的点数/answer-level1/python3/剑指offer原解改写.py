### 代码

```
class Solution:
    def twoSum(self, n: int) -> List[float]:
        if n < 1: return []
        freq = [[0 for _ in range(6*n+1)] for _ in range(2)]
        flag = 0
        for i in range(1,6+1):
            freq[flag][i] = 1
        
        for k in range(2, n+1):  # k 为当前骰子数
            for i in range(k):
                freq[1-flag][i] = 0
            for i in range(k, 6*k+1):
                freq[1-flag][i] = 0
                for j in range(1, 6+1):
                    freq[1-flag][i] += freq[flag][i-j]
            # 修改标志位以交换状态数组
            flag = 1- flag

        total = math.pow(6, n)
        # ratio = list(map(lambda x: x / total, prob[flag]))
        res = []
        for i in range(n, 6*n+1):
            res.append(freq[flag][i] / total)  # prob = freq / total
        return res


```