### 解题思路
一开始莫名想到了布尔积运算……就想着用矩阵去做，结果没找到合适的切入点。
步入正题，因为是求最小公共子串，我拿其他所有子串仅仅和第一个串做对比即可，构建一个字典来存储首串的各元素在最小字串中，依据索引映射的布尔关系。
提交了很多次……才发现了一些没注意到的地方：
1、长度的缩减是不可逆的，需要设置一个minlen变量来记录最短的长度，并在字典中[minlen]值设为零，来切掉冗余部分。
2、1——>0的变化也是不可逆的，在置1时需要判断该处是否已经被赋值过。
3、因为我偷懒用的字典结构，所以在遍历时得给索引排序一下。

评论区里ASCII码和zip的解法太惊艳了，膜。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ptr = 1
        base = {}
        res = ""
        if len(strs) == 1:
            return strs[0]
        elif len(strs) == 0:
            return res
        else:
            minlen = len(strs[0])
            while ptr <= len(strs) - 1:
                if len(strs[ptr]) == 0 or len(strs[0]) == 0:
                    return res
                minlen = min(len(strs[ptr]), minlen)
                base[minlen] = 0
                for i in range(minlen):
                    if strs[0][i] == strs[ptr][i] and i not in base:
                        base[i] = 1
                    if strs[0][i] != strs[ptr][i]:
                        base[i] = 0
                ptr += 1
            k = sorted(base)
            for n in k:
                if base[n] == 1:
                    res += strs[0][n]
                else:
                    break
            return res

```