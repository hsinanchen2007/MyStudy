![image.png](https://pic.leetcode-cn.com/6fc3dcc876c07fd7de3fa4f8dd3a663943f1fd6c6b843eb2da89713bc9cc7b28-image.png)

贡献一个一行版，提交时间可以参考，人少排名没啥意义。

时间复杂度是$O({N}^{2})$，看到数据规模就知道算法有问题了，但是字符整体生成后比较其实比较快，可以承受10000的长度，单独循环比较就必然超时了。

```python []
class Solution:
    def lastSubstring(self, s: str) -> str:
        return max(s[i: ] for i in range(len(s)))
```

超时的解法，超在了第21个用例，全是a的长用例，但是类似算法，其他某些语言暴力似乎也是可以过的。

```python [1]
class Solution:
    def lastSubstring(self, s: str) -> str:
        n = len(s)
        q, k = [*range(n)], 0
        while True:
            if len(q) == 1:
                return s[q[0]: ]
            c_max, t = 'a', []
            for i in q:
                if i + k >= n:
                    break
                if s[i + k] > c_max:
                    c_max = s[i + k]
                    t = [i]
                elif s[i + k] == c_max:
                    t += [i]
            q = t
            k += 1
            
```
