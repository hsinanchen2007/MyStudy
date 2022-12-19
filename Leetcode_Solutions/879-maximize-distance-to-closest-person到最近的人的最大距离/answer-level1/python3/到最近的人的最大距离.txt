### 解题思路
我的思路：先用双指针法求出一段空位的起始下标和结束下标，如果下标不是数组首末位置，则取0的中间下标落座，否则取首末位置落座。
但是代码实现能力弱的一批，改了好久才写出来...
时间复杂度:O(N)
空间复杂度:O(1)
### 代码

```python3
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        if len(seats) == 1:
            return 1
        start = 0
        end = 0
        zuobiao = 0
        zuobiao_len = -1
        for i in range(len(seats)):
            if seats[i] == 0:
                end = i
                if i==len(seats)-1 and end-start >= zuobiao:
                    zuobiao = i-start
            else:
                current_len = end-start
                if current_len > zuobiao_len:
                    if start == 0 and seats[start] == 0: # 若开头在起始位置
                        zuobiao = end-start+1
                    else:
                        haha = int((end + start+1) / 2) - start
                        if haha > zuobiao:
                            zuobiao = haha
                    zuobiao_len = current_len
                start = i
                end = i
        return zuobiao
```