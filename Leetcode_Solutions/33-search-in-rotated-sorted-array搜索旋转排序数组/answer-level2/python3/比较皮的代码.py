话不多说，直接上代码
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return -1 if target not in nums else nums.index(target)
```
什么？只有一行，对，没错，而且还通过了
