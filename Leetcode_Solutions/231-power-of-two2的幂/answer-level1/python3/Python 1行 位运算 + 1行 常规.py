```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
	"""
	:type n: int
	:rtype: bool
	"""
        return n > 0 and n & n - 1 == 0
```
- 2 的幂的二进制形式最高位一定是1，其余为0
- 用常规思路也行
	```python
	class Solution(object):
	    def isPowerOfTwo(self, n):
		return n > 0 and 2**int(math.log2(n)) == n
	```
