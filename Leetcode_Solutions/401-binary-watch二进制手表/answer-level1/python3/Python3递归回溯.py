采用递归回溯的方法，因为一个LED灯代表的数值只能计算一次，递归函数参数除了当前时刻，剩余LED灯数外，还需要记录备选LED灯的起点i(索引小于i的LED灯不再考虑)。
hour和minute可以用一个列表表示，但个人认为这样更清晰。
combination第一个元素为小时，第二个元素为分钟。
```
def readBinaryWatch(self, num: int) -> List[str]:
        hour = [1, 2, 4, 8]
        minute = [1, 2, 4, 8, 16, 32]
        h_len, m_len = len(hour), len(minute)
        res = []
        
        def time(combination, led,  start):
            if led == 0:
                if combination[1] < 10:
                    res.append(str(combination[0]) + ':0' + str(combination[1]))
                else:
                    res.append(str(combination[0]) + ':' + str(combination[1]))
            else:
                for i in range(start, h_len + m_len):
                    if i < h_len:
                        combination[0] += hour[i]
                        if combination[0] < 12:
                            time(combination, led - 1, i + 1)
                        combination[0] -= hour[i]
                    else:
                        combination[1] += minute[i - h_len]
                        if combination[1] < 60:
                            time(combination, led - 1, i + 1)
                        combination[1] -= minute[i - h_len]
        
        cur = [0] * 2
        time(cur, num, 0)
        return res
```
