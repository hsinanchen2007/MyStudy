### 解题思路
滑动窗口法 + 两个哈希表的方法需要每次窗口内对两个哈希表相同字符的出现次数进行比较，所以这种普通方法的时间复杂度为O(NP)，其中N为s的长度，而P为p中不同字符的个数。
我们可以同样利用窗口内的重复元素减少匹配次数，记录一个变量diff，代表窗口内的字符需要满足条件仍需要的字符数量，然后对下一步进来的字符和出去的字符判断diff的变化，这样仅仅多加了一个变量，就可以将时间复杂度降到O(N)级别（因为每次只需要访问两个两个字符在两个字典中的值和p的长度无关）。diff具体变化可以参照下面代码。

### 代码

```python
class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        len_s = len(s)
        len_p = len(p)
        if len_s < len_p:
            return []
        char_dict = {} # 记录的是目标字符及对应个数
        win_dict = {} # 记录的是窗口内目标字符及对应个数
        diff = len_p
        # 初始化两个字典
        for ch in p:
            char_dict[ch] = char_dict.get(ch, 0) + 1
            win_dict[ch] = 0
        for i in range(len_p):
            if s[i] in win_dict:
                if win_dict[s[i]] < char_dict[s[i]]:
                    diff -= 1
                win_dict[s[i]] += 1
        p, q = 0, len_p - 1
        res = []
        if diff == 0:
            res.append(0)
        while q + 1 < len_s:
            q += 1
            if s[q] in win_dict:
                if win_dict[s[q]] < char_dict[s[q]]:
                    diff -= 1
                win_dict[s[q]] += 1
            if s[p] in win_dict:
                if win_dict[s[p]] <= char_dict[s[p]]:
                    diff += 1
                win_dict[s[p]] -= 1
            p += 1
            if diff == 0:
                res.append(p)
        return res
```