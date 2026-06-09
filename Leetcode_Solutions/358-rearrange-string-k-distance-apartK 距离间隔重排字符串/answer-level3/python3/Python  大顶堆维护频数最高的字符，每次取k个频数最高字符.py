![image.png](https://pic.leetcode-cn.com/edfa39ea0765b1f79a0c436c0e206ac3cb0b7483ac09ecf5bba165666dcd3a8c-image.png)


```
'''
统计单词计数，用大顶堆维护当频数最多的字符，题目要求的
目标字符串是连续k个不出现重复的字符，所以每次从大顶堆取
出k个字符，组成长度是k的子串，放到当前字符串末尾，可选
的字符种类越多，越不容易出现无法摆放情况，所以先消耗
剩余数量多的字符，出现无法组成长度k字符串时候，失败返回空
'''


from queue import PriorityQueue
from collections import Counter
class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        k = max(1, k)

        max_heap = PriorityQueue()
        for ch, cnt in  Counter(s).items():
            max_heap.put_nowait((-cnt, ch))

        ans = []
        while not max_heap.empty():
            pick_num = min(len(s) - len(ans), k)
            if max_heap.qsize() < pick_num:
                return ''

            buf = []
            for i in range(pick_num):
                cur = max_heap.get()
                ans.append(cur[1])
                if cur[0] + 1 != 0:
                    buf.append((cur[0] + 1, cur[1]))

            for pair in buf:
                max_heap.put(pair)

        return ''.join(ans)
```
