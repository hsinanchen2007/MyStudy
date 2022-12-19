
1、先按照少的排好（前面多放置一个空字符）
2、多的字符逐个插入即可。
该方法的时间复杂度应该为O(max(A,B))，比官方的O(A+B)要快一丢丢，不知道理解是否正确，请多指正！


![图片1.png](https://pic.leetcode-cn.com/51fa29c52efbcb65cf3017468356f6c0ef1889be8392722e893fdbe028e7410f-%E5%9B%BE%E7%89%871.png)

```python []
class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        flag = A > B
        dic = {True: (A, B, 'a', 'b'), False: (B, A, 'b', 'a')}
        res, n = [''] + [dic[flag][3]] * dic[flag][1], dic[flag][1] + 1
        for i in range(dic[flag][0]): res[i % n] += dic[flag][2]
        return ''.join(res)
```
