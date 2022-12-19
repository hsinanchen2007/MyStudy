1、先对k进行优化，如果k=len（nums），最后相当于没有移动过，通过取模运算把k限制在有效的次数内（肯定小于n）
2、移动k次，相当于把数组后面的k个元素，整体移到数组的前面；而数组原来的前面部分整体移到后面。相当于是看成两个分片的交换。

```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n
        nums[n-k:],nums[:n-k] = nums[:n-k],nums[n-k:]

```
