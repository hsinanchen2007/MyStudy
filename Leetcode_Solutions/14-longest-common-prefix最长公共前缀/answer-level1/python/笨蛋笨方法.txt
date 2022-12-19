### 解题思路

![image.png](https://pic.leetcode-cn.com/1524b5bd57e1010343dd4cd0809484bee8b8c4fd67c23ca0c632e94ce052a3f6-image.png)
因为题目要求是最长公共前缀，所以应该用减法而不是加法；
加法缺点在于运算量比较大，而减法随着每次的比对运算量会越来越小。

1.首先判断下为空的情况
2.然后把各字符串拿出来和第一个字符串相比较，如果不符就削去第一个字符串一位继续比
3.最后得出结论

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            a = ""
            return a 
        a = strs[0]
        for i in strs[1:]:
            ss = i.find(a)
            while i.find(a) != 0:
                a = a[:-1]
        return a 

```