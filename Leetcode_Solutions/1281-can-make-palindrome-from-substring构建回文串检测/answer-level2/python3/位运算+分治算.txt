目标，计算从 start到end出现次数为奇数次的字母的个数c ,如果 c <=2*k+1 则一定可以变成回文串 因为c最大是26，所以k如果>=13 则一定可以变成回文串

预处理s
把 ‘a’-'z' 看成一个26位的二进制数，如果某个字母出现了奇数次，记为1 如果出现了偶数次，记为0
这样 d[i] 表示到s 的第i个字符时，表示的数字

处理 queries

奇数-奇数 = 偶数
奇数-偶数 = 奇数
偶数-偶数 = 偶数
偶数-奇数 = 奇数

正是 异或 的结果

对结果取二进制中1的个数，参考 java 版 bitCount 方法，分治 计算1的个数，需要5步
1 每1位计算 1的个数和
2 每2位计算 1的个数和
3 每4位计算 1的个数和
4 每8位计算 1的个数和
5 每16位计算 1的个数和




```python
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        d = [0]*len(s)
        k = 0
        for i, c in enumerate(s):
            k ^= 1 << (ord(c) - ord("a"))
            d[i]=k
        ans = []
        for start, end, k in queries:
            if k<13:
                c = d[end]
                if start > 0:
                    c ^= d[start-1]
                c = (c & 0x55555555) + ((c >> 1) & 0x55555555)
                c = (c & 0x33333333) + ((c >> 2) & 0x33333333)
                c = (c & 0x0f0f0f0f) + ((c >> 4) & 0x0f0f0f0f)
                c = (c & 0x00ff00ff) + ((c >> 8) & 0x00ff00ff)
                c = (c & 0x0000ffff) + ((c >> 16) & 0x0000ffff)
                ans.append(c <= (2 * k + 1))
            else:
                ans.append(True)
        return ans
```
**复杂度分析**
* 时间复杂度 O(n+m),n是s的长度，m是queries的长度
* 空间复杂度 O(n),存储n个数字
