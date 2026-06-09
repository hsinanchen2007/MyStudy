### 解题思路
别学，就是刷题，我预计这个是不合适的，index很可能是O(n)的复杂度，但是在Python手册里没找到；
sort是logn的一个复杂度，也说不好，index可能会比n小，毕竟这个运行速度有点快，竟然超过了90%，可能是数据集太小了；
如果有人知道，请指点；
in的时间复杂度是n；
这个题其实就是分治！

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return -1 if not target in nums else nums.index(target)
```