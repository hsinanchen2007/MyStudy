### 解题思路
对评论区的一个小伙伴的代码进行了改进，得到如下结果。
![image.png](https://pic.leetcode-cn.com/8ca5c805f8d00555e7230c0dc561a225c96580a070c021320808a5f0df1c4623-image.png)
小伙伴的源码是：
return len(s) -max(0,sum([s.count(i)%2 for i in set(s)])-1)

首先讲一下这种思路：
当s长度为1，简化为 len(s)-max(0,1-1) = 1
当s长度大于1，就是统计其中计数为奇数的，再对2取余，对所有余数求和，相当于是把所有不能匹配回文符的字符去掉，总和减1是因为可以放一个在回文符的最中间。

改进思路：
1.对其中的set(s)进行了替换，Python自带的set函数去重时复杂度较高，自行撰写的这部分。
2.相比对列表生成器，map操作更快，map返回的是迭代器，更快。
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ss = set()
        for i in range(len(s)):
            ss.add(s[i])
        return len(s)-max(0,sum(map(lambda x:s.count(x)%2,ss))-1)
```