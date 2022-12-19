### 解题思路
理解题意之后，两个单词可"合并编码"意味着具有相同后缀，且即使是不连续的单词也可能可以合并编码。
所以直观的想法是：
- 为了便于连续比较，首先要将单词按后缀顺序排序
- 为了便于后缀排序，需首先对所有单词执行一遍倒序
- 标记一个当前可合并编码的最长单词cuRword，且curWord可能可合并的区间长度不止2个单词，只要这些单词具有逆序后的公共前缀
- 感谢评论区大佬 @adohuge 的意见，对单词排序时进行逆序，可保证curWord永远"不小于"新单词（包括长度和前缀均不小于）
- 对单词列表中所有单词逐一判断：
-- 如果新单词与curWord可以合并，直接进入下一循环
-- 否则，需要更新结果长度，即加curWord+1的长度，同时更新curWord为新单词
-   注意最后一个curWord未在循环中加入，所以再补充一下即可

由于字符串不允许更改，所以逆序和之后切片比较的过程实际上都占用了空间，意味着本方法的空间复杂度会很低O(n*k)

### 结果
![image.png](https://pic.leetcode-cn.com/96916fe7fb380e1751d0c5884c514a86afe07222619377f0ab0d1a22a1730b9a-image.png)

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = [word[::-1] for word in words]
        words.sort(reverse=True)#按单词大小逆序排序，确保前面的单词"不小于"后者
        ans, curWord = 0, words[0]
        for word in words[1:]:
            if curWord.startswith(word):#如果前缀相同，说明可压缩
                continue
            else:
                ans += len(curWord)+1#加上当前可压缩区间的单词长度
                curWord = word
        ans += len(curWord) + 1 #加上最后一个长度
        return ans
```
欢迎关注个人公众号：小数志，高频更新中……

