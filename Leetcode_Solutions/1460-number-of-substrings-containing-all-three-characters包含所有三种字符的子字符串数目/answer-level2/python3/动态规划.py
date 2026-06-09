# 思路
遍历整个字符串，每次迭代时加上以当前字符结尾的合法字符串数量。下面只需要每次计算这个数量即可
每次更新，'a','b','c',三个字符所在的索引最右侧位置，三个字符位置的最小值即为当前字符结尾的最短字符串的最左端，记这个字符串为A。
从字符串A向左可以扩充的字符串数量恰为A的最左端索引。
时间复杂度：O(n)
空间复杂度：O(1)
# 代码
```
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        cnt_ch={'a':0,'b':0,'c':0}
        cnt=0
        for i in range(len(s)):
            cnt_ch[s[i]]=i+1
            cnt+=min(cnt_ch['a'],cnt_ch['b'],cnt_ch['c'])   
        return cnt
```
