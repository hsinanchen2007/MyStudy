# ```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        return (lambda r: r + [x | 1<<n-1 for x in r[::-1]])(self.grayCode(n-1)) if n else [0]
# ```
# - 前4个结果：
# 	```
	[0]
	[0 1]
	[00 01 11 10]
	[000 001 011 010 110 111 101 100]
# 	```
# - 递归方程：这一步结果 = 上一步结果 + 上一步结果的镜像并在每个二进制数字前面加一位1
# - << 左移符号，即在二进制表示后加一位 0 ，例子：3<<1 等于 6`（011 → 110）`，相当于 3 * 2的1次方
# - x | 1<<n-1 就是在十进制数字 x 的二进制前面加一位1之后的十进制结果，比如 x = 1，有 1 | 10 等于 110
# - 循环可以避免一些不必要的操作，会比递归快一些：
# 	```python
	class Solution:
	    def grayCode(self, n: int) -> List[int]:
		r = [0]
		for i in range(n):
		    r.extend([x | 1<<i for x in r[::-1]])
		return r
# 	```
# - 或者直接背格雷码的公式🥶吧：
# ```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        return [i ^ i >> 1  for i in range(1 << n)]
# ```

