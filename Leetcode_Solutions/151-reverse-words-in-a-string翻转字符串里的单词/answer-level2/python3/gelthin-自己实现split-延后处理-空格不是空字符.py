### 解题思路
进一步的习题 [186. 翻转字符串里的单词 II](https://leetcode-cn.com/problems/reverse-words-in-a-string-ii/)
[557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)



同习题 [面试题58 - I. 翻转单词顺序](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/solution/gelthin-diao-yong-split-by-gelthin/)

+ 当碰到一个" ", 处理先前得到的 tmp， 注意到如果两个连续的 空格，那么很可能 tmp 是空字符串。
+ 延后处理，在最后一次还需要额外处理一下 tmp 对应的字符。

#### 空格不是空字符，空格的 boolean 值是 True， 空字符才是 False, 这个一定要小心。
之前在习题[面试题67. 把字符串转换成整数](https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/solution/gelthin-kong-ge-zi-fu-de-boolzhi-wei-true-by-gelth/)
碰到过此。

#### 官方解答还提供了其他的解法
+ 去除额外空格后，使用求解 [189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)，反转两次的做法，先对整个序列做一个大的反转，然后在对每个单词做一个反转，最后再去除额外空格，这样对于C++ （字符串可变）可以保证是 O(1) 的空间复杂度。  
[另一题的题解讨论区](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/solution/gelthin-reversed-wu-fa-zuo-yong-yu-zi-fu-chuan-by-/) 腾讯面试官考了这个题，但是是char数组，还有他说双O(N)太复杂优化，这TM还能咋优化，有没有大佬说一下？空间复杂度优化到O(1)?还要求是正序的？例如 this is a teacher -> teacher a is this。 如果字符串是可变的，空间复杂度可以降低为 O(1)


+ 也有提供了用双端队列的做法，但是双端队列在这里用的有些牵强。


### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        ## 这里自己来实现 split() 功能，注意延后处理
        words = []
        # 先找到第一个不为空的地方
        i = 0
        while i<len(s):
            if s[i] != " ": # 空字符串是 None, 但空格不是 None
                break
            i += 1
        tmp = ""
        for j, x in enumerate(s[i:], i):
            if x != ' ':
                tmp += x
            else:
                if tmp != "": # 这里 "hello world!  "(接两个空格，不用此就过不去)
                # 在第一个空格处，tmp = "world!", 在第二个空格处，tmp = ""
                    words.append(tmp)
                    tmp = ""

        if tmp != "":
            words.append(tmp)
                
        words = words[::-1]
        return " ".join(x for x in words)

```