

执行用时:__72 ms__, 在所有 python3 提交中击败了__88.24%__的用户
内存消耗:__13.9 MB__, 在所有 python3 提交中击败了__5.01%__的用户
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        registered = []
        applicant = []
        
        for i in s:
            if i not in applicant:
                applicant.append(i)
            else:
                if len(applicant) > len(registered):
                    registered = applicant
                tail = applicant.index(i)
                applicant = [*applicant[tail+1:], i]
                
        if len(applicant) > len(registered):
            registered = applicant
        return len(registered)
```
新手第一次写，主要的思路是在内存里存两个表：一个是现有的character list， 还有一个是目前最长的character list。阅读各位大佬的post之后发现方法的本质是滑窗法，有一点区别在于我看到的滑窗法一般用绝对位置（字符在字符串中的位置），我用了相对位置（字符在保存的character list中的位置）。

算法的逻辑是遍历字符串，如果当前字符没有在applicant里，就附加进applicant；如果在applicant里找到当前字符i（惭愧，用i遍历显然不符合编程规范），做判断，如果registered（最长的character list）没有applicant长，registered就被赋值为applicant，然后找applicant里究竟是哪个位置是i（先前已经判断过一定存在这么一且仅有一个位置满足），applicant里就只有从该位置向后的所有值再加上i。注意，applicant里所有的字符都按照顺序排列。

内存消耗的原因大概是我在内存中保存了字符串的缘故。当然我无聊也尝试了把registered改为int型的数值：
``` python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        registeredLength = 0
        applicant = []
        
        for i in s:
            if i not in applicant:
                applicant.append(i)
            else:
                if len(applicant) > registeredLength:
                    registeredLength = len(applicant)
                tail = applicant.index(i)
                applicant = [*applicant[tail+1:], i]
                
        if len(applicant) > registeredLength:
            registeredLength = len(applicant)
        return registeredLength
```
内存消耗还是一样，时间也一样。

各位大佬不吝赐教，小生感激不尽。