### 解题思路
比较第i小的数和总个数-i +1 （因为包括这个数）的大小，若第i小的数大于等于n-i+1（就是有多少个比这个数大的数），那么 h 就是n- i +1
1. 给citation排序
2. 比较

### 代码

```python3
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        if citations == [] or max(citations) == 0:
            return 0 
        c = sorted(citations)
        for i in range(len(c)):
            if c[i] >= (len(c) - i ):
                return (len(c) - i )
                break 
```