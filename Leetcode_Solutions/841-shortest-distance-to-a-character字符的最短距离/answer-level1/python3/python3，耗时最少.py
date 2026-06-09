
#### 基本思路：
1. 找出S中每个C的位置；
2. 在每两个C之间去设置中间字符距离；

e.g. S长度为10，C的位置为2,5
1. 找到第一个index(C)为2， 将2之前的距离一次设置为2,1,0
2. 从三开始找到下一个位置为5，找到2-5中间的位置为(5+2)//2=3, 将3的位置距离设置为1， 将4-5的距离设置为1,0
3. 5至字符串结尾再无字符C，则将5以后的位置距离一次设置为1,2,3,4,5

#### 时间复杂度：
先遍历一遍S找字符C的位置O(N),再把相邻C之间的位置设置距离O(N),因此总的时间复杂度为O(N)；
#### 空间复杂度：
创建跟字符串S长度一样的List，复杂度为O(N)。

#### 总耗时：
40ms，战胜100%，哈哈

#### 代码
```
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        lenS = len(S)
        C_list = [-1] * lenS
        C_start, C_end = -1, -1
        for i, s in enumerate(S):
            if s == C:
                if C_start == C_end == -1:
                    C_start = 0
                    C_end = i
                    for j in range(C_start, C_end + 1):
                        C_list[j] = C_end - j
                else:
                    C_start = C_end + 1
                    C_end = i
                    mid_pos = (C_end + (C_start - 1)) // 2
                    for j in range(C_start, mid_pos + 1):
                        C_list[j] = j - C_start + 1
                    for j in range(mid_pos + 1, C_end + 1):
                        C_list[j] = C_end - j
        for j in range(C_end + 1, lenS):
            C_list[j] = j - C_end
        return C_list
```
