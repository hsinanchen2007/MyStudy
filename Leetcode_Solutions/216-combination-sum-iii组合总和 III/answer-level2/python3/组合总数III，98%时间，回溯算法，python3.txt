### 解题思路
回溯函数参数：
1. temp：当前回溯路径中的数字组成的数组
2. K：还需要累加多少个数字
3. summary：距离目标值n还差多少
4. num：接下来累加的值要在(0, num]之间

回溯函数解释：
- 如果summary小于0，说明加多了，返回
- 如果K等于0，且summary等于0，符合题意，记录结果
- 如果K等于0，且summary大于0，说明已经加了K个数字但是没达到目标，剪枝
- 递归调用回溯函数，这里我们从大到小遍历

### 代码

```python3
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def backtrack(temp, K, summary, num):
            if summary < 0:
                return
            if K == 0 and summary == 0:
                res.append(temp)
            if K == 0 and summary > 0:
                return
            for i in range(num, 0, -1):
                backtrack(temp+[i], K-1, summary-i, i-1)
        res = []
        backtrack([], k, n, 9)
        return res


```