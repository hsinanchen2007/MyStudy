看官方题解很多人都觉得被Hint坑了（我也是……）
但是死缠烂打之下还是把从矮个子开始的解法写出来了，时间复杂度同官方题解一样为$O(n^2)$.

## 思路

1. 将`people`排序（升序）
2. 初始化`res = [None] * n`
3. 根据Hint，从最矮的开始排，并且每次排完我们把该人忽略，这样下一个人又是最矮的
4. 这样下来，每个人`people[i]`的位置都由其`k`值决定位置，由于我们忽略之前排的所有人，我们只需从头数有几个`None`，当`None`的数量等于k的时候，`res`里下一个`None`的位置就是`people[i]`的位置

代码如下：
```python
for i in range(len(people)):
    k = people[i][1] 
    count = j = 0
    while j < n and count <= k: # 记录此人之前的None的个数（相当于忽略已排好的人）
        if res[j] is None:
            count += 1
        j += 1
    res[j-1] = people[i]
```

这里我们还要解决一个问题：如果碰到相同个子的人怎么办？
此时的`k`值需要减去在`people[i]`之前与他个子相同的人数：
```python
if i > 0 and people[i][0] == people[i-1][0]:
    same_cnt += 1
    k -= same_cnt

if i < n-1 and people[i][0] != people[i+1][0]:
    same_cnt = 0 # 当下个人的个子变化时，same_cnt归零
```

## 完整代码
```python
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort()
        n = len(people)
        res = [None] * n
        same_cnt = 0
        for i in range(n):
            k = people[i][1]
            if i > 0 and people[i][0] == people[i-1][0]:
                same_cnt += 1
                k -= same_cnt
            count = j = 0
            while j < n and count <= k:
                if res[j] is None:
                    count += 1
                j += 1
            res[j-1] = people[i]
            if i < n-1 and people[i][0] != people[i+1][0]:
                same_cnt = 0
        return res
```