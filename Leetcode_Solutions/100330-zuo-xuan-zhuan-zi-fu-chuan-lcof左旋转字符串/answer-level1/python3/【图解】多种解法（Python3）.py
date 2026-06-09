实际上主站的189题，以及编程之美都有类似的题目，因此这个题目还算比较经典。另外我本人还总结了数组，链表的循环移位算法，感兴趣的可以看下 https://lucifer.ren/blog/2019/12/11/rotate-list/


![](https://pic.leetcode-cn.com/c6bfaa77d8aad118fab1f1edeac0d37317376588f5297b51f6d1cad7d95067fd.jpg)


# 空间换时间

我们将s + s 形成一个两倍长度的字符串， 这样`s[k:n + k]` 就是我们要求的结果。

![](https://pic.leetcode-cn.com/771647cce640593c3787b60e2680561c28ede6994c563c5b1237d519c4db9f26.jpg)

## 思路


## 代码

```python
class Solution:
    def reverseLeftWords(self, s: str, k: int) -> str:
        n = len(s)
        s = s + s
        return s[k:n + k]
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

# 巧用模运算

## 思路

这种方法虽然巧妙，但是我们花费了额外的 N 的空间，能否不借助额外的空间呢？答案是可以的，我们可以假想已经存在了另外一个相同的 s1，并且我们将它连接到 s1 的末尾。注意这里是假想，实际不存在，因此空间复杂度是 O(1)。那么如何实现呢？

答案还是利用求模。

## 代码


```python
class Solution:
    def reverseLeftWords(self, s: str, k: int) -> str:
        n = len(s)
        res = ''
        for i in range(k, k + n):
            res += s[i % n]
        return res
```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
