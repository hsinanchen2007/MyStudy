### 解题思路
这道题滑动窗口法的思路在精选题解里都说过了，在此不再赘述，但是想讲一下实现上的小细节。
为了判断窗口内的字符是否满足条件，精选题解中需要比较目标字符在窗口内出现的次数是否大于等于t中的字符个数，这样进行比较会很浪费时间，所以添加了一个集合set()用于记录目前窗口内不满足条件的字符，这样通过判断set是否为空就可以确定窗口内的子串是否满足条件。

### 代码

```python
class Solution(object):
    def minWindow(self, s, t):
        """ 
        :type s: str
        :type t: str，t中可能出现重复字母
        :rtype: str
        """
        t_dict = {} # 要求的字符及数量
        s_dict = {} # 当前窗口内的字符及数量
        l_set = set() # 当前窗口内缺少的字符
        for ch in t:
            if ch not in t_dict:
                s_dict[ch] = 0 
                t_dict[ch] = 1
                l_set.add(ch)
            else:
                t_dict[ch] += 1
        p = q = 0
        min_len = float('inf')
        res = ''
        while q < len(s):
            # 首先移动q指针，令窗口内包含所有目标字符
            while q < len(s) and len(l_set) != 0:
                ch = s[q]
                if ch in t_dict:
                    s_dict[ch] += 1
                    if s_dict[ch] >= t_dict[ch] and ch in l_set:
                        l_set.remove(ch)
                q += 1
            while len(l_set) == 0:
                temp_len = q - p + 1
                if temp_len < min_len:
                    min_len = temp_len
                    res = s[p:q]
                ch = s[p]
                if ch in t_dict:
                    s_dict[ch] -= 1
                    if s_dict[ch] < t_dict[ch]:
                        l_set.add(ch)
                p += 1
        return res
```