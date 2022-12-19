1）按照start区间小到大，和end区间大到小排序
2）设置两个标记，一个i和一个j，初始化 j 比 i 大1
3）循环所有区间例如 [[0, 2], [1, 3], [2, 6], [3, 5], [6, 7]]

1.  [0, 2] 的 2  大于 [1, 3] 的start = 1 但是小于 end = 3，因此我们要'删除[1, 3]' (因为这样可以使得[0, 2] 跟 [2, 4]离得更远，end=3肯定会离后面区间更近的)。实际上我们不删除元素，只是将标记i 不移动，j ++，表明中间那个我们删除了，count ++计数我们删除了1个。  
2.  [0, 2] 跟 [2, 4] 比较发现是一样的，因此count不+1。但是由于i和j都需要移动到新的比较位置，此时由于中间‘删除了[1, 3]’。使用 i = j, j ++ 来使得i 掠过 ‘[1, 3]’删除的元素。  
3.  i 在[2 ,6]  j 在 [3, 5]上。由于 end = 6 大于 后面的 end = 5。因此前面i指向的更靠近更后面的元素，所以删除的是[2, 6]。此时i 移动到j位置，j + 1即可。此时count也需要 —— 1


```
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:(x[0],-x[1]))
        count = 0
        i = 0
        for j in range(1,len(intervals)):
            if intervals[i][1] > intervals[j][1]:  # 删除最小的元素
                count += 1
                i = j
            elif intervals[i][1] > intervals[j][0]: # 将会删除中间元素
                count += 1
            else:
                i = j
        
        return count
```

