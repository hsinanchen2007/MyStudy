```Python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = {}  # 统计t中的字频，用need字典保存
        for a in t:
            need[a] = need.get(a, 0) + 1
        l = r = 0  # 滑动窗口实现
        res, _need = s+'0', sum(need.values()) > 0  # _need：当前窗口是否还需要扩展来包含t
        while r < len(s) or not _need:
            if _need:  # 如果还需要扩展则右滑末尾
                if s[r] in need:
                    need[s[r]] -= 1  # 更新所需字频中的值
                    _need = any(map(lambda x: x > 0, need.values()))  # 更新_need的状态
                r += 1
            else:  # 不需要扩展则右滑开头
                if r-l < len(res):
                    res = s[l:r]  # 更新答案
                if s[l] in need:
                    need[s[l]] += 1  # 更新所需字频中的值
                    _need = any(map(lambda x: x > 0, need.values()))  # 更新_need的状态
                l += 1
        if len(res) > len(s):  # 没有找到满足的子串
            return ''
        return res
```
