### 解题思路

采用动态规划的方法进行求解，有好几种动态规划的方法
这里只介绍一种，设 f[i] 表示以 s[i] 为结尾的无重复字符最长子串，则 result = max (len(f[i]), i=1,2,...)
状态转移方程如下：
 if s[i] 没在 f[i-1] 中出现过，f[i] = f[i-1] + s[i]；
 if s[i] 在 f[i-1]中出现过，f[i] = h + s[i] 这里的 h 是 f[i-1] 从 s[i] 出现的位置起往后的全体字符.

易错点:
1. 子序列 和 子串是有区别的，子序列可以不连续，子串必须连续。
2. 因为规定是字符串，顺序是不能切换的，所以需要用 list 结构来存储当前子串
3. 注意不要误以为 s[i] 在 f[i-1] 中出现过，就要全部清空，令 f[i] = [] + s[i]. 实际上虽然完整的f[i-1]无法用上，但 f[i-1] 的在s[i]出现位置的后一段可以用上。


### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = 0
        current = []
        for x in s:
            if x in current:
                result = max(result, len(current))
                for i, t in enumerate(current):
                    if t == x:   ## 找到当前解 current 中出现 x 的位置，把x和x前一段丢掉, 保留x之后可用的一段
                        break
                current = current[i+1:]
                # current = [] BUG. current 后一段也是可用的
            current.append(x)
        result = max(result, len(current))  ## 延后处理
        return result
```