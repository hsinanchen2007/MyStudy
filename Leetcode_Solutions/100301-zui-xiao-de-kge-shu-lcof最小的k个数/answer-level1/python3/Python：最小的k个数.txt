### 解题思路
本质排序，不要学我，这个写法不能算算法，但是Python的sort是真的好用，只有logn的复杂度
可以通过部分排序过程，得到前几个数，比如插排

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        return arr[0:k]   
```