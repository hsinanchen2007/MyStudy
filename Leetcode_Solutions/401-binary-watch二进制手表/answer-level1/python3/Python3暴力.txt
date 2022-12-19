# 思路：
根据实际生活经验，手表走完12小时即可遍历所有时间可能：
`0：00，0：01，···，1：00，1：01，···，11：58，11：59`
然后对每一个可能的时间`hh：mm`检查有几个亮灯的`1`，满足`n`即记录到列表中，最后返回列表保存的结果。
# 注意：
由于`minutes`是从`00~59`而非`0~59`，故利用`zfill()`函数填充字符`0`：
```
zfill(self, width, /)
    Pad a numeric string with zeros on the left, to fill a field of the given width.
    The string is never truncated.
```
# 代码：
```
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        def ones(s):
            return bin(s).count('1')
        re=[]
        for h in range(12):
            for m in range(60):
                times=ones(h)+ones(m)
                if times==num:
                    re.append(str(h)+':'+str(m).zfill(2))
        return re
```

# 结果：
执行结果：通过
执行用时 :44 ms, 在所有 python3 提交中击败了81.73%的用户
内存消耗 :13.9 MB, 在所有 python3 提交中击败了5.10%的用户