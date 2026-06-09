#### 1、思路

以输入为 ”abca” 为例，假设目前选择第一个字符，我们选择第 1 个 a 与第 4 个 a 之后，剩下的字符串为 'bca' 或 ‘abc’，这实际上属于同一类型的选择，所以保留其中一个即可。

为了方便去重，先对输入进行排序，这样 'abca' 排序后变成 ‘aabc’，只需要判断前面选择的字符是否与当前选择的字符相同即可。

#### 2、代码

```python

class Solution:

    def permutation(self, S: str) -> List[str]:
        ans = []

        S = sorted(S)

        def backtrack(pre_str, r_str):
            if not len(r_str):
                ans.append(pre_str)
            else:
                pre = ''
                for i in range(len(r_str)):
                    if r_str[i] != pre:
                        backtrack(pre_str + r_str[i], r_str[:i] + r_str[i + 1:])
                    pre = r_str[i]

        backtrack('', S)
        return ans

```

#### 3、执行结果

![截屏2020-03-1115.55.19.png](https://pic.leetcode-cn.com/9ab55db71caed81223ed63f4c4a7c85aeeb03ab24bba52c391758a0278b5cf88-%E6%88%AA%E5%B1%8F2020-03-1115.55.19.png)