该解法执行时间 40ms

思路：

1. 过滤掉无值和只有一个值的情况

2. 取出列表中最短的字符串（如果有最长公共前缀，最多也就是其中最短的一个值）

3. 遍历列表，判断每一个字符串在从开头截取出来的同等长度下是否一样，一样的话，计数加1；不一样直接跳过

4. 判断本次循环结束最终的计数是否与列表长度一致，一致，说明这就是最长公共前缀

5. 不一致，将当前最短值截取掉最后一位，加上死循环，再次进行判断

6. 如果没有公共前缀，在最短值切成空字符串时，判断相等，循环结束



```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        # 取出列表中最短的值
        s_min = min(strs, key=len)
        while 1:
            t_num = 0  # 本次循环中能对上的数量
            for i in range(len(strs)):
                if s_min == strs[i][:len(s_min)]:
                    t_num += 1
            if t_num == len(strs):
                return s_min
            s_min = s_min[:-1]

        return ""
```

