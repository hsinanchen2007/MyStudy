### 解题思路
首先记录每个元素出现的次数，把它存成字典，然后对字典进行排序。从出现次数最多的元素开始相加，直到值大于长度的一半
### 代码

```python3
import math
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        count_dict = dict()
        for i in arr:
            if i in count_dict:
                count_dict[i] += 1
            else:
                count_dict[i] = 1
        count_tuple = sorted(count_dict.items(),key = lambda d:d[1],reverse = True)
        if len(arr)%2 == 0:half = len(arr)/2
        else:half = math.ceil(len(arr)/2)
        amount = 0
        size = 0
        for i in count_tuple:
            amount += i[1]
            size +=1
            if amount >= half:break
        return size
```