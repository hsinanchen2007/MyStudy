# Counter + 常规排序


## 思路

简单的做法是：

- 先统计每个数字出现的次数frequents
- 然后根据出现次数进行排序
- 每次取出最大值，直到我们取出的频率和大于arr的一半。

![](https://pic.leetcode-cn.com/6f4ac023941180f8e9b74e919e2511b8c0923d93f87c950238e5ffe2f47769fc.jpg)

![](https://pic.leetcode-cn.com/57aef94b32de6de24e1b31e7566cbdf3c808155326c5d5ebfdbfd74497986898.jpg)

![](https://pic.leetcode-cn.com/c8ac1488c5ad40e3d91f913dd85f0a371ac3b1c2364af80aeb99e0463943c89a.jpg)




## 代码

```python
from collections import Counter

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        frequents = sorted(Counter(arr).values())
        i = 0
        cnt = 0
        while i < len(arr) // 2:
            i += frequents.pop(-1)
            cnt += 1
        return cnt
```


**复杂度分析**
- 时间复杂度：$O(NlogN)$ （假设我们使用的是比较排序）
- 空间复杂度：由于我们借助了frequents数组， 因此空间复杂度为 $O(D)$ ，其中D为数组中不同数字的个数


# Counter + 桶排序

## 思路

当然上述的排序我们也可以使用桶排序来空间换时间

题目给定了范围 1 <= arr[i] <= 10^5， 因此我们需要准备最多10^5 + 1 个桶，这通常是可以接受的。

![](https://pic.leetcode-cn.com/6f4ac023941180f8e9b74e919e2511b8c0923d93f87c950238e5ffe2f47769fc.jpg)



![](https://pic.leetcode-cn.com/c8ac1488c5ad40e3d91f913dd85f0a371ac3b1c2364af80aeb99e0463943c89a.jpg)


![](https://pic.leetcode-cn.com/e380c8b6b33f31f30f53f61e11b5de0d9f5bb4191b3c824df698447d138c3a85.jpg)

## 代码

```python
from collections import Counter
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
            
        counts = Counter(arr).values()
        max_value = max(counts)
    
        buckets = [0] * (max_value + 1)
        
        for count in counts:
            buckets[count] += 1
            
        cnt = 0
        arr_numbers_to_remove = len(arr) // 2
        bucket = max_value
        while arr_numbers_to_remove > 0:
            max_needed_from_bucket = math.ceil(arr_numbers_to_remove / bucket)
            set_size_increase = min(buckets[bucket], max_needed_from_bucket)
            cnt += set_size_increase
            arr_numbers_to_remove -= set_size_increase * bucket
            bucket -= 1
            
        return cnt
```

# Counter + 最大堆


## 思路

由于我们每次都取最大的频率，我们可以联想到最大堆，使用最大堆无须对整个数组进行排序。

注意： 由于Python只有最小堆，因此我这里hack了一下。 对频率求相反数，这样就转化成了最小堆。

## 代码


```python
from collections import Counter
from heapq import heapify, heappop


class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        frequents = list(map(lambda a: -1 * a,  Counter(arr).values()))
        heapify(frequents)
        i = 0
        cnt = 0
        while i < len(arr) // 2:
            i -= heappop(frequents)
            cnt += 1
        return cnt
```


**复杂度分析**
- 时间复杂度：$O(klogN))$，其中k为我们的答案，N为数组长度。
- 空间复杂度：由于我们借助了frequents数组， 因此空间复杂度为 $O(D)$ ，其中D为数组中不同数字的个数。（堆排序是就地算法，因此没有额外空间耗费）

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
