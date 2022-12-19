### 解题思路
1.m肯定小于或者等于nums1的长度
2.只取nums1的前m个数的话，那么就是说nums[m]以及nums[m]以后的数都是可以舍弃的
3.反正nums1只要前m个数，那么后面的数先舍弃谁都一样，调用pop方法从最后一个删起
4.要删了nums1下标为m到len(nums1)的数，每次删一个，就需要删len(nums1)-m次.可以for循环range(len(nums1)-m)或者range(m,len(nums1)),每次循环都pop一下，就得到了“切片”后的nums1
5.剩下直接对nums2进行切片，然后再调用sort方法，ok

小白求教：
为什么我的代码最后面不能直接写成
nums1.extend(nums2[:n]).sort()
看了一下extend方法定义，是因为没有返回值所以不能这样使用吗？等一个大佬给我指点确认一下
### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """      
        for p in range(m,len(nums1)):
            nums1.pop()
        nums1.extend(nums2[:n])
        nums1.sort()
```