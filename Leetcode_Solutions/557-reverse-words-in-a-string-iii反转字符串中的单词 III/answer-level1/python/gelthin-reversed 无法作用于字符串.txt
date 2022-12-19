### 解题思路
[官方题解评论区讨论](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/solution/fan-zhuan-zi-fu-chuan-zhong-de-dan-ci-iii-by-leetc/317099)

腾讯面试官考了这个题，但是是char数组，还有他说双O(N)太复杂优化，这TM还能咋优化，有没有大佬说一下？空间复杂度优化到O(1)?还要求是正序的？例如 this is a teacher -> teacher a is this。 如果字符串是可变的，空间复杂度可以降低为 O(1)
但这个讨论题更类似 习题 [151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/solution/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode/) 的解法，不过那个稍微更复杂。


本题中字符串翻转可以使用视图 [::-1]， 但是 reversed 无法作用于字符串
因为 reversed 会形成一个新的对象生成器 list_reverseiterator 


### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        # 现将单词逐个取出来，然后选择
        left = 0
        res = ""
        for i in range(len(s)):
            if s[i] == " ":
                res += s[left:i][::-1]   # 可以用 [::-1] 但是 reversed 无法作用于字符串
                res += " "
                left = i+1
        res += s[left:][::-1]
        return res
```