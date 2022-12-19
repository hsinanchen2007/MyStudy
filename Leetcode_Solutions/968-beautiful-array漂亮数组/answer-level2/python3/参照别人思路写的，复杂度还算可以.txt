### 解题思路
首先分成基数组和偶数组，这2个天然漂亮了。
然后基数里面比如1、3、5、7, 3一定不能挨着1和5， 5一定不能挨着3和7，因此打散放。直到小于等于2。
![image.png](https://pic.leetcode-cn.com/d1f21b5e5e3a302350f6e1e8db0b7d2e07cf823ec1d72e1595df24cb4e1276e0-image.png)

### 代码

```python3
class Solution:
    def beautifulArray(self, N: int) -> List[int]:
        def _helper(nob_list):
            if len(nob_list) <= 2:
                return nob_list

            b1 = _helper(nob_list[::2])
            b2 = _helper(nob_list[1::2])
            return b1 + b2

        odd_list = list(range(1, N+1, 2))
        even_list = list(range(2, N+1, 2))
        beatiful_list = _helper(odd_list) + _helper(even_list)
        return beatiful_list
        
```