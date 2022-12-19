### 解题思路
拜读各位大佬之后自己抄写了一份
自己最初的思路跟各位用哈希表的大佬是相同的，统计字符串中各个字符的出现次数，偶数次的不管，奇数如果出现两次或以上就认定为非回文串的排列字符串。
我发生的问题一，最初尝试了自己之前解题用过的字母频谱的办法，跑单词成功了，但是在提交时候发现本次课题中会出现26个字母以外的字符，故放弃此方法。
我发生的问题二，在放弃了字母频谱这个方法后，尝试用循环各个字符进行逐个比对的方法统计各个字符的个数。
但是因为无法处理好重复统计问题，最终求助于大家的解题步骤，顺便学习了哈希表的使用。
感谢各位，望不吝赐教
### 代码

```python
class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        char_counter = {}
        odd_counter = 0
        for char in s:
            if char not in char_counter.keys():
                char_counter[char] = 1
            else:
                char_counter[char] +=1
        for num in char_counter.values():
             if num % 2 != 0:
                 odd_counter +=1
        if odd_counter > 1:
            return False
        else:
            return True



```