### 哈希表+最大堆

* step1：建立哈希表{elem: num}，统计每个元素出现的次数
* step2：把所有的次数取相反数放进列表中（因为heapq是最小堆，建立最大堆需要手动取反）
* step3：建立最大堆，每次pop出来出现次多的次数值，减去它得到计算此时的长度，判断是否删去一半了。

* 时间复杂度：O（nlogn）第一步为O（n），n为arr长度；第二步为O（klogk），k为distinct（arr）的长度；第三步：log（k）
* 空间复杂度：O（k），最差为O（n）

```python []
from collections import defaultdict
import heapq

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        arr_len = len(arr)
        # step1
        elem_num = defaultdict(int)
        for i in range(arr_len):
            elem_num[arr[i]] += 1
        # step2
        num_list = []
        for num in elem_num.values():
            num_list.append(-num)
        # step3
        heapq.heapify(num_list)
        curr_sum = 0
        res = 0
        while(curr_sum < arr_len//2):
            curr_sum -= heapq.heappop(num_list)
            res += 1
        return res
```