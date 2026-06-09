### 解题思路
因为挨着的数比如1/2/3/4/5， 2*2=1+3， 3*2=2+4，因此把挨着的数打散即可。
![image.png](https://pic.leetcode-cn.com/c2905c86d8a275bd14b7ac7aa7dcbcf65eb854f1007641d529b72940a28d7993-image.png)

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

        n_list = list(range(1, N+1))
        beatiful_list = _helper(n_list)
        return beatiful_list
        
```