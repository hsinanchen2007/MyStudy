```python
def maxDistToClosest(seats):
    max_count = 0
    # 开头/结尾为0, 则特殊处理
    if seats[0] == 0 and 1 in seats:
        max_count = max(max_count, seats.index(1))
    if seats[-1] == 0 and 1 in seats:
        max_count = max(max_count, seats[::-1].index(1))

    # 找到0的最大个数
    count, start, end = 0, None, None
    for i in range(len(seats)):
        if seats[i] == 0 and start is None:
            start = i
        if seats[i] == 1 and start is not None and end is None:
            end = i
        if start is not None and end is not None:
            count = max(count, end - start)
            start, end = None, None
    if count % 2 == 0:
        return max(max_count, count // 2)
    return max(max_count, count // 2 + 1)
    
print(maxDistToClosest([1,0,0,0,1,0,1]))
print(maxDistToClosest([1,0,0,0]))
```