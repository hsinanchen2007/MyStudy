### 解题思路
先產生一個與最大時間等長的向量 
依序將時間區間填入 +1 
再觀察重疊時間的最大值 

### 代码

```python3
import numpy as np

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        m = np.array(intervals)
        max_v = np.max(m)

        vec = np.zeros((max_v))
        for i in intervals:
            vec[i[0]:i[1]] += 1

        return int(np.max(vec))    

```