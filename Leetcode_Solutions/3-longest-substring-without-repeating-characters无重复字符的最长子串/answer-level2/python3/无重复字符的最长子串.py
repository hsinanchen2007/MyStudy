### 解题思路
其实我的这个解题思路没有花多久的时间，如下：
a           
ab        b
abc       bc       c        
abca      bca      ca      a
abcab     *bcab*     cab     ab     b
abcabc    bcabc    cabc    abc    bc    c
abcabcb   bcabcb   cabcb   abcb   bcb   cb   b
abcabcbb  bcabcbb  cabcbb  abcbb  bcbb  cbb  bb  b
但是至于如何去实现呢，我就走了很多弯路。
1.横向去实现还是纵向去实现
最终发现纵向(一个横向结束完以后下一个横向）实现是合适的
2.每个横向怎么遍历
比如abca bca ca a这个横向，a是肯定不会重复的因为它是单字符，然后看c是否和a重复判断ca可否，再看b是否和ca重复判断bca可否。所以是倒序。
截至标志：
可见bcab中出现重复，那么abcab就不用判断了，它辐射的以下区域也不用判断了。
这个截至判断最好用while+break来判断，不要用for+break来判断，基于python中while和for的机制。
相信到这里，大家应该明白了为什么是倒序遍历，因为从后面可以判断出前面的重复并截至。
3.max标志
有一段小插曲，大家可以看代码理解。
总之弯还是很多的，所以实现是一门技术，我还得修炼修炼。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 字符串转数组
        str_list = list(s)
        length = len(str_list)

        max = 1
        if length == 0:
            max = 0
        jizhi = -1
        for i in range(1,length):
            cur_len = 1
            j = i - 1
            while j > jizhi:
                if str_list[i] == str_list[j]:
                    break
                cur_len = i - j + 1
                j -= 1
            # 如果是break出来的
            if j != jizhi:
                jizhi = j
            if cur_len > max:
                max = cur_len

        return max
```