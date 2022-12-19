这题确实够难，它比上一题[第139-单词拆分](https://leetcode-cn.com/problems/word-break/solution/dan-ci-chai-fen-python-by-fei-ben-de-cai-zhu-uc4q0/)上升了一个层次，在第139题我分别介绍了回溯法和动态回归法，然而在此题中这两种方法都不太灵，尤其是回溯法，那更是吐血，不管怎么搞，都是超出时间限制。我先讲讲回溯法吧。

方法一：回溯法
这种方法应该是最直接最容易想到的，当时是除了暴力法哈。题目不就是想问字典 wordDict内的单词能不能构成字符串s吗，只要从头至尾依次遍历，不断切分，如果发现有子串刚好是在字典 wordDict中，立马切分出来。继续相同的操作，直至切分的所有子串都恰好在字典 wordDict中，那说明该字符串s能切分，取出切割的结果即可。是不是很easy?
代码如下：
```Python
class Solution(object):
    # 本题采用回溯法
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        if len(s) == 0 or len(wordDict) == 0:
            return
        # 获取wordDict内单词的最大长度
        max_length = max([len(word) for word in wordDict])
        # 定义一列表用来保存最终的分割结果
        split_s = []

        def back(start=0, sub_str_list=[]):
            if start >= len(s):
                new_str = " ".join(sub_str_list)
                if new_str not in split_s:
                    split_s.append(new_str)
            for end in range(start, start+max_length):
                sub_str = s[start:end+1]
                if sub_str in wordDict:
                    back(end+1, sub_str_list+[sub_str])

        back()
        return split_s
                

if __name__ == "__main__":
    s = "catsanddog"
    wordDict = ["cat", "cats", "and", "sand", "dog"]
    split_s = Solution().wordBreak(s, wordDict)
    print(split_s)
```
思路是很好的，但就是超出时间限制了。我记得当时一度是放弃了。行，话都说到这个份儿上了，我也不怕丢丑了，没错，这道题我三四个月之前做过一天，没搞出来，气不过就没管了，今天心情好就拿出来玩玩了，其实是这一页的题目就剩这几道了哈哈哈哈哈。
咳咳咳，废话说多了，我们进入正题，既然回溯法行不通，那我们就来试试动态规划法呗。

方法二：动态规划法
这道题所采用的动态规划法我觉得是有点类似前两天写的两篇文章内的DFS（深度优先遍历）的，即两次遍历，第一次是从头至尾遍历，获取flag标记数组。第二次遍历是从尾至首的，结合flag数组来判断条件。具体操作如下：
动态规划求解的第一步是要获取flag标记数组，此题亦是如此，具体如下图：
![f6bcef6c5906ff5dcf6756c8df2a458.jpg](https://pic.leetcode-cn.com/79ba350d490fce47548d1bb81be95c68479f11ad4f01536bd9d35712cf4a3e94-f6bcef6c5906ff5dcf6756c8df2a458.jpg)
flag数组拿到了，接下来要做的就是写出状态转移方程了。具体如下：
![afbc0b4c5c42d7326b2568fc39ccf74.jpg](https://pic.leetcode-cn.com/bc5e0f2daa2dd08f896c266152b52a7784cee33a5325956fec9f2941d40eaddf-afbc0b4c5c42d7326b2568fc39ccf74.jpg)
以上这两个关键数值拿到了，下面就是前面提到的从尾至首遍历了，因为在计算flag时已经算是从首至尾遍历了。那这次遍历主要就是参考状态转移方程中我框出来的那个部分了，即右边判断切分的子串是否在wordDict字典中，左边一直是递归判断左子串切分成的单词是否均在wordDict字典中。

代码如下：
```Python
class Solution:
    def wordBreak(self, s, wordDict):
        if len(s) == 0 or len(wordDict) == 0:
            return []
        word_set = {word for word in wordDict}
        dp = [False for _ in range(len(s))]
        dp[0] = s[0] in word_set

        for r in range(1, len(s)):
            # 如果整个单词就直接在 word_set 中，直接返回就好了
            # 否则把单词做分割，挨个去判断
            if s[:r + 1] in word_set:
                dp[r] = True
                continue
            for l in range(r):
                # dp[l] 写在前面会更快一点，否则还要去切片，然后再放入 hash 表判重
                if dp[l] and s[l + 1: r + 1] in word_set:
                    dp[r] = True
                    break
        split_s = []

        # 从尾往首遍历
        def dfs(end=len(s), sub_str_list=[]):
            # 如果最后切分的单词刚好就在字典中，那可以直接取出结果了
            if s[:end] in word_set:
                sub_str_list.append(s[:end])
                # 这儿注意，因为sub_str_list添加的子串都是从s的右边往左边添加的
                # 因为后面有个pop（）操作，所以这儿得先复制
                sub_str_copy = sub_str_list[:]
                sub_str_copy.reverse()
                new_str = " ".join(sub_str_copy)
                split_s.append(new_str)
                sub_str_list.pop()
            for start in range(end-1, -1, -1):
                # 此处刚好对应状态转移方程2
                if dp[start] and (s[start+1:end] in word_set):
                    dfs(start+1, sub_str_list+[s[start+1:end]])
        dfs()
        return split_s


if __name__ == "__main__":
    s = "pineapplepenapple"

    wordDict = ["apple","pen","applepen","pine","pineapple"]
    split_s = Solution().wordBreak(s, wordDict)
    print(split_s)
```
执行效率中等吧，在40%左右。
![image.png](https://pic.leetcode-cn.com/2f12bf93cdd6446283119bdc804655f43d304661af5738b9ba725f2599ef2f17-image.png)

如果大家有更好的方法，希望积极留言啊！！！

