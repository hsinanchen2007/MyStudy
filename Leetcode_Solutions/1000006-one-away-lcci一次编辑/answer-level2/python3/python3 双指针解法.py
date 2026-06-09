```
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        # 双指针解法
        # 零次编辑的情况
        if first == second:
            return True

        f_len = len(first)
        s_len = len(second)
        # 如果是插入或者删除，字符串长度差为1，并且其中双指针某一个不同时，截取后面的应该是相同的
        # 如果是替换，那么只要一次不同，后面的就必须相同
        if f_len>s_len:
            # 调换first, second的值，保证first是较短的那一个
            first, second = second, first
            f_len, s_len = s_len, f_len

        if s_len-f_len>1:
            return False
        
        for i in range(f_len):
            if first[i] == second[i]:
                continue
            else:
                return first[i:] == second[i+1:] or first[i+1:] == second[i+1:]

        # first为空字符串的情况
        return True
```
