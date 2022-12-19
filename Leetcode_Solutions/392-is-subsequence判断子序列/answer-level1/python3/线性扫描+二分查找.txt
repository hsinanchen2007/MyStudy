```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:

        # # 方法一, 暴力求解, 扫描所有的数组
        # if len(s) > len(t):
        #     return False
        # s_s = 0
        # t_s = 0
        # while s_s < len(s) and t_s < len(t):
        #     if t[t_s] == s[s_s]:
        #         s_s += 1
            
        #     t_s += 1
        
        # if s_s == len(s):
        #     return True
        
        # return False

        # 方法二, 使用二分查找, 这个查询子串数量很多的情况下可以加快速度
        # 极端情况下, 时间复杂度应该是O(100 * log(len(t))), 但是实际上log里面的长度应该是远小于len(t)
        # 毕竟有26个字母. 估算应该能快个100倍左右吧
        from collections import defaultdict
        from bisect import bisect
        if len(s) > len(t):
            return False
        
        if len(s) == 0:
            return True

        char_to_index_dict = defaultdict(list)

        for ix, sig_t in enumerate(t):
            char_to_index_dict[sig_t].append(ix)
        
        first_word_list = char_to_index_dict.get(s[0])
        if first_word_list is None:
            return False
        
        pre_word_index = first_word_list[0]

        for i in range(1, len(s)):
            word_list = char_to_index_dict.get(s[i])
            if word_list is None:
                return False
            
            ix = bisect(word_list, pre_word_index)

            if ix == len(word_list):
                return False
            
            pre_word_index = word_list[ix]
        
        return True
```
