### 解题思路
dp[i]表示前i位所能组合的结果(i从0开始)，对于"12254",dp[2]表示"122"所能翻译的结果。
dp[i+2] = g(i)*dp[i] + dp[i+1],对于长度为i+2的字符串，可分成两种情况(注意这里是闭区间)
- case 1: [0:i+1][i+2]两个部分
- case 2: [0:i][i+1:i+2]两个部分
对于case1,可能的结果由[0:i+1]的组合种类确定即dp[i+1]
对于case2:
- [i+1:i+2]在0~25范围之内，则由[0:i]的组合种类确定即dp[i],g(i) = 1
- [i+1:i+2]不在0~25范围之内,则这样划分是行不通的,g(i) = 0
- 注意"0"开头的，如"06"也是不属于0~25范围的

### 代码

```python3
class Solution:
    def translateNum(self, num: int) -> int:
        num = str(num)
        if len(num) == 1:
            return 1
        res = [0 for i in range(len(num)+1)]
        res[0] = 1
        res[1] = 1
        for i in range(1, len(num)):
            res[i+1] = res[i] + self.judge_range(i, num)*res[i-1]
        return res[-1]

    def judge_range(self, index, num):
        if num[index-1:index] == "0":
            return 0
        if 0 <= int(num[index-1:index+1]) <= 25:
            return 1
        else:
            return 0
```