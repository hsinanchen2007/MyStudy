### 解题思路
此题采用动态规划的方法，时间复杂度为O(n2), 空间复杂度为n2，mem[i, j]记录分别以i，j为结尾的相同两字符串的最长的长度，mem[i,j] == mem[i-1,j-1] + 1 if s[i-1] == s[j-1] else 0;
PS:
1. 注意mem table的下标是从0 到length(S) + 1 左闭右开，而S中的index坐标是从0到lengthS(s) 左闭右开，二者相差1；
2. mem此处用的的是defaultdict，充当二维数组，因为字典中是请允许tuple: 形如(i,j)作为key的；
3. 为避免mem无值产生，总是使得values里面保留一个0，供边界条件下，max(values)能够返回有效值
4. 此题针对 'aaaaa' 这样的输入，返回的结果是4，说明子串是可以重叠的；如果条件改为不允许子串重叠，则只需要在判断S[i-1] == S[j-1] 时，加上对后一个子串的长度上的保证，即 if if S[i-1] == S[j-1] and mem[i-1, j-1] < (j - i)时才更新mem即可；

### 代码

```python3
class Solution:
    def longestRepeatingSubstring(self, S: str) -> int:
        from collections import defaultdict
        mem = defaultdict(lambda: 0, {})
        length = len(S)
        for i in range(1, length + 1):
            for j in range(i+1, length + 1):
                if S[i-1] == S[j-1]:
                    mem[i, j] = mem[i -1, j-1] + 1
        values = [0] + list(mem.values())
        return max(values)

```