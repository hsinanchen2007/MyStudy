# 欢迎参考[我的简书](https://www.jianshu.com/p/4926d9d42e1e)，持续更新哦！ 😄😄😄

# 难度：简单

# > 给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。

# ## 朴素解法
# 1. 遍历S，找到所有 C 的位置索引；
# 2. 遍历S，找到同所有 C 的位置索引的距离，取最小值；

# 复杂度为 O(n^2)

# ### python 描述
# ``` python
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        index = [i for i in range(len(S)) if S[i] is C]
        
        if len(index) > 0:
            return [min([abs(i-j)  for j in index ])for i in range(len(S))]
        else:
            return [float('inf') for i in S]
# ```

# ## 双指针解法
# 1. 设置 right、left 指针；
# 2. right 前进，同时更新 right 与 C 的位置；
# 3. right 遇到 C 停下，等 left 指针追上 right，同时更新 left 与 C 的位置；
# 4. 重复 2、3 直到 right 到达 S 末尾；

# 复杂度为 O(n)

# ### python 描述
# ```python
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        left = 0
        result = [float('inf') for i in S]

        for right in range(0, len(S)):
            if S[right] is C:
                for i in range(left, right + 1):
                    result[i] = min(result[i], right - i)
                left = right
            elif S[left] is C:
                result[right] = min(result[right], right - left)

        return result
# ```
