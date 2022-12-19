尊重知识产权
[最长回文子串（Python](https://www.jianshu.com/p/6f226c9180e2)


这篇文章是为这样的菜鸟准备的，就是处在似懂非懂的阶段。我大致浏览了其他作者的博文，写的比较就是，得心领神会才更好吧。
好，进入正题！
**回文子串**的意思是的字符串s等于它的逆。也就是'1234321'.

**最长**，这个不用解释了吧。比如有一个回文子串长度是2，下一个回文子串是4，那么4会替换掉2.

好，那么怎么递归呢？

**递归**是什么意思呢？就是重复某些步骤或是算法。

那么它的临界点是什么呢？
- 
1. 字符串长度为1，则就是s[0]. 
2. 字串有两个字符，那么这两个字符一定相等。

重复算法
-
当子串有多个字符时，判断根据首位字符是否相等以及除去首位字符剩余子串是否为回文串判定当前子串。

那么咱们把上面说的话，用公式表示出来呀。

- 构造二维`矩阵dp`，维度为`len(s)*len(s)`，`dp[i][j]`表示子串`s[i:j+1]`是否为回文串，`i`和`j`均为下标索引，范围在`0~len(s)`之间，且`i<j`，因此`dp矩阵`中的每一个变量均为布尔量；
可能您还是不太理解为什么这样做，但是这都是套路呀。
- .构造状态转移方程，考虑两种情况

```python []
dp[i][j] ---> s[i]==s[j]  if j-i<=1
dp[i][j] ---> s[i]==s[j] and dp[i+1][j-1]  if j-i>1
```

```
class Solution:
    def longestPalindrome(self, s):

        dp = [[False]*len(s) for _ in range(len(s))]
        max_start, max_len = 0, 0                       # 最长回文子串开始位置及长度
        for j in range(len(s)):                     # 右指针先走
            for i in range(j+1):                 # 左指针跟着右指针
                if j - i < 2:                    # 前两种情况
                    dp[i][j] = (s[i] == s[j])
                else:                                   # 最后一种情况
                    dp[i][j] = (s[i] == s[j]) and dp[i+1][j-1]
                # cur_substr = s[i:j+1]          # 当前考察的子串
                cur_len = j + 1 - i              # 当前子串长度为 j + 1 - i
                if dp[i][j] and max_len < cur_len:

                    max_start = i
                    max_len = cur_len

        return s[max_start:max_start + max_len]
```
 欢迎各位大神交流讨论

