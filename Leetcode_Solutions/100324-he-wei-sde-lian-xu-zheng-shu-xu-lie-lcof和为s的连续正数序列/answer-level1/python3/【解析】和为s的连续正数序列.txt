### 解题思路
这道题的规模是10的5次方，O(n)级别的复杂度应该是可以通过的。本人用的是比较简单的办法。
从上一道打卡题开始有了关于时间复杂度测算的一个习惯，就是建立一个cnt变量，在时间复杂度最高的那个地方每遍历一次就加上1，然后进行不同规模的数据测试，最后看一下大概的cnt大小。本人此题定义的cnt在target为1000时是3871，10000时是50282，100000时是618013，整体还算可以。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        num = int(target / 2) + 1
        print("num\t" + str(num))
        res = []
        cnt = 0
        for start in range(1, num + 1):
            cur = start
            tmp = []
            tmp.append(start)
            for end in range(start + 1, num + 1):
                cnt += 1
                if cur > target:
                    break
                if cur < target:
                    cur += end
                    tmp.append(end)
                if cur == target:
                    if len(tmp) > 1:
                        res.append(tmp[:])
                        break
                    else:
                        break
        print("----------------")
        print("cnt: " + str(cnt))
        return res
```