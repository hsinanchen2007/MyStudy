首先我们将speed和efficiency按照efficiency降序排列：
![WeChat Screenshot_20200316123839.png](https://pic.leetcode-cn.com/b9952164ee3e60775afdb8b424bb9934a59c4c9d3d17aff31686bc5ed6942e98-WeChat%20Screenshot_20200316123839.png)
python代码：
```pyhton
people = [(efficiency[i], speed[i]) for i in range(len(speed))]
people.sort(key = lambda a: a[0], reverse=True)
```

对数组的前K个元素来说，我们可以选择小于等于k个人，只需要获得最大的团队表现值。
对于第k+1个及以后元素（假设坐标为i），如果我们选择当前值，则必须在前[0, i)个元素中选择k-1个值(共k个人)，才能获得最大团队表现值。因为要使用该元素的effiiciency。efficiency一定，每个人的速度值大于0，多一人总比少一人好😏。
python代码：
```python
heap, total = [], 0
rst = 0
for i in range(len(people)):
    if i < k:
        heapq.heappush(heap, people[i][1])
        total += people[i][1]
        rst = max(rst, total * people[i][0])
    else:
        if people[i][1] > heap[0]:
            popped = heapq.heappop(heap)
            heapq.heappush(heap, people[i][1])
            total = total - popped + people[i][1]
            rst = max(rst, total * people[i][0])
                
```
这里还要用到一个小顶堆，维护选中的k个人的速度。（如果n <= k，我们就不需要该小顶堆。直接一趟遍历找出最大团队表现值即可。这里为了统一，就不写这么多分支了。）
当i < k时，速度值直接进堆，然后更新最大团队表现值。
当i >= k后，如果当前速度值小于等于小顶堆里的最小值，那么我们选择他不会带来最大团队表现值的提升（因为efficiency是降序的）。因此直接pass掉。否则，更新小顶堆。使小顶堆维持前[0, i)项的速度前k大的值，然后更新最大团队表现值。

遍历结束后，按要求返回结果即可。
```
return rst % (10**9 + 7)
```