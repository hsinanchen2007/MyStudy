

这里只是简单解释，详细看我[知乎回答](https://www.zhihu.com/question/39948290/answer/883302989)的最后一个例子。

首先进行如下定义：
![image.png](https://pic.leetcode-cn.com/dbf4b0e84407cade0334ddb2be7821e839878d3162cf9ce32321572441c85c53-image.png)


状态转移方程为：
![image.png](https://pic.leetcode-cn.com/1f5c7a1e9907a6034b0f538fbbd5dc46f8265759d358ee36942573ee996cc326-image.png)



可读性高版
```python []
# 状态转移函数（目标1）
def f(pattern, i_p, string, i_s, results):
    # 当前是星号
    if pattern[i_p] == '*':
        m_ij = pattern[i_p -1] == string[i_s] or pattern[i_p -1] == '.'
        r = results[i_p - 2][i_s] | results[i_p - 1][i_s] | results[i_p][i_s - 1] & m_ij

    # 当前不是星号
    else:
        m_ij = pattern[i_p] == string[i_s] or pattern[i_p] == '.'
        r = results[i_p - 1][i_s - 1] & m_ij

    return r


# 主匹配函数
def is_match(string, pattern):

    # 初始化二维数组（目标2）
    len_string = len(string) + 1  # 给二维数组加哨兵，所以+1
    len_pattern = len(pattern) + 1
    results = [[False] * len_string for i in range(len_pattern)]
    results[0][0] = True
    pattern = '_' + pattern  # 兼容哨兵
    string = '_' + string

    # 异常处理
    if len_pattern == len_string == 1:
        return True
    if len_pattern == 1:
        return False
    if pattern[0] == '*':
        return False

    # 外循环遍历pattern（目标3）
    for i_p in range(1, len_pattern):

        # 这里是哨兵处理相关（与星号的情况1相关）
        if pattern[i_p] == '*':
            results[i_p][0] = results[i_p - 2][0]

        # 内循环遍历string（目标3）
        for i_s in range(1, len_string):
            # 状态转移函数（目标1），以及复用中间结果（目标2）
            results[i_p][i_s] = f(pattern, i_p, string, i_s, results)


    return results[-1][-1]


class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        return is_match(s, p)
```



加速版（战胜96.1%）
```python []
class Solution:




    def isMatch(self, s: str, p: str) -> bool:

        # 初始化二维数组
        s_len = len(s) + 1   # 给二维数组加哨兵，所以+1
        p_len = len(p) + 1
        results = [[False] * (s_len) for i in range(p_len)]
        results[0][0] = True
        p = '_' + p     # 兼容哨兵
        s = '_' + s

        # 异常处理
        if p_len == s_len == 1:
            return True
        if p_len == 1:
            return False
        if p[0] == '*':
            return False


        for i_p in range(1, p_len):

            # 针对*匹配为0次
            if p[i_p] == '*':
                results[i_p] = results[i_p - 2]

            for i_s in range(1, s_len):
                # 当前是星号
                if p[i_p] == '*':
                    m_ij = p[i_p-1] == s[i_s] or p[i_p-1] == '.'
                    results[i_p][i_s] |= results[i_p - 1][i_s] | results[i_p][i_s - 1] & m_ij

                # 当前不是星号
                else:
                    m_ij = p[i_p] == s[i_s] or p[i_p] == '.'
                    results[i_p][i_s] |= results[i_p - 1][i_s - 1] & m_ij

        return results[-1][-1]
```
