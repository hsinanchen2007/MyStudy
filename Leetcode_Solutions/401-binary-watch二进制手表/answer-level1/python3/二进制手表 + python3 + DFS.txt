####  方法1：DFS + 回溯

**代码：**

```python []
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        # 范围0:00 ~ 11:59，因此上面最多三个亮，下面最多5个亮。 

        def find(i, num, max_, res, tmp):
            '''
            i：灯的位序
            num：当前还剩余多少可以亮的灯
            max_：时针和分针分别对应的最大值
            res：存储时间的类别
            tmp：临时存时
            '''
            if num == 0:
                res.add(str(tmp))
                return
            if tmp + 2 ** i <= max_:
                find(i + 1, num - 1, max_, res, tmp + 2 ** i)  # 选
                find(i + 1, num, max_, res, tmp)  # 不选
            else:
                return

        hour = set()
        minute = set()
        final = []
        for n in range(num + 1):
            if n <= 3 and num - n <= 5:
                find(0, n, 11, hour, 0)  # 时针
                find(0, num - n, 59, minute, 0)  # 分针
                for h in hour:
                    for m in minute:
                        if len(m) == 1:
                            final.append(h + ':' + '0' + m)
                        else:
                            final.append(h + ':' + m)
                hour = set()
                minute = set()

        return final
```