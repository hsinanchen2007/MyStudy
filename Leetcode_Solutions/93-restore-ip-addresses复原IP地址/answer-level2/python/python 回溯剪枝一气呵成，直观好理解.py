```python
    def restoreIpAddresses(self, s: str) -> List[str]:
        if not s:
            return []
        def restore(s: str, remain: int):  # 从s里恢复几个ip段
            if remain == 1:  # 结束条件，仅当剩的数在[0,255]且不存在'01','022'这种情况时返回
                if -1 < int(s) < 256 and str(int(s)) == s:
                    return [s]
                return [] # 否则返回空
            res = []
            if remain <= len(s) <= 3*remain-2:
            # 除掉1位后剩余至少remain-1个字符，至多3*(remain-1)个字符
                for i in restore(s[1:], remain-1):
                    res.append(s[:1]+'.'+i)
            if int(s[:2]) > 9 and remain+1 <= len(s) <= 3*remain-1:
            # 除掉2位（真正的两位数）后剩余至少remain-1个字符，至多3*(remain-1)个字符
                for i in restore(s[2:], remain-1):
                    res.append(s[:2]+'.'+i)
            if 99 < int(s[:3]) < 256 and remain+2 <= len(s) <= 3*remain:
            # 除掉3位（真正的三位数）后剩余至少remain-1个字符，至多3*(remain-1)个字符
                for i in restore(s[3:], remain-1):
                    res.append(s[:3]+'.'+i)
            return res
        return restore(s, 4)
```