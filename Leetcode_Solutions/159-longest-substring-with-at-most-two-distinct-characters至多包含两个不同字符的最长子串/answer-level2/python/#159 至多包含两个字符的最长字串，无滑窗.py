### 解题思路
时间复杂度：O(n)
空间复杂度：O(1)

变量：
lastSet：是一个set，记录当前子串里包含的不同字符，set长度为1或2
lastChar，lastCharCount：记录当前字符的前一个字符和它连续出现的次数
sub，maxSub：记录当前子串长度和当前最长子串长度

算法：
字符串长度小于3的直接返回字符串长度。
用字符串前两个字符更新所有变量，现在lastSet包含前两个字符组成的set，如果前两个字符相同，set的长度应该是1，lastCharCount就是2，佛则set长度为2，lastCharCount是1。不管两个字符是否相同，当前子串和最长子串的长度都是2。
循环遍历字符串，循环从字符串第三个字符开始，如果当前字符在lastSet里，当前子串可以继续增长，但是需要判断是否更新上一个字符和它的计数，如果当前字符和lastChar一样，那么只用更新lastCharCount，否则lastChar变成当前字符，lastCharCount变为1，然后更新maxSub。如果当前字符不在lastSet里，说明lastSet需要更新，且当前子串也不能继续增长了，因为有第三个字符出现了，在做更新前先更新当前的maxSub，然后sub变为前一个字符连续出现的次数（lastCharCount）加1，lastSet变为当前字符和前一个字符，lastChar变为当前字符，lastCharCount变为1。循环结束后返回maxSub和sub中最大的那一个。
### 代码

```python3
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        if len(s) < 3:
            return len(s)
        
        lastSet, lastChar = set(s[:2]), s[1]
        lastCharCount = 2 if len(lastSet) == 1 else 1
        maxSub = sub = 2

        for i in range(2, len(s)):
            currentChar = s[i]
            if currentChar in lastSet:
                sub += 1
                if currentChar == lastChar:
                    lastCharCount += 1
                else:
                     lastChar = currentChar
                     lastCharCount = 1
                maxSub = max(sub, maxSub)
            else:
                maxSub = max(sub, maxSub)
                sub = lastCharCount + 1
                lastSet = set([lastChar, currentChar])
                lastChar = currentChar
                lastCharCount = 1

        return max(sub, maxSub)

```