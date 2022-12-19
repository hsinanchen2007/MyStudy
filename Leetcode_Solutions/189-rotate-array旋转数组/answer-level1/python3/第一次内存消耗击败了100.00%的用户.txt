### 解题思路
先k = k%length
取k和length的最大公约数为j
从头开始以k为间隔遍历list
用length/j控制不重复遍历
一次遍历解决问题
新手欢迎批评指正

第一次内存消耗击败了100.00%的用户 记录鼓励一下自己 sjj继续加油！
### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        import math
        length = len(nums)
        k = k%length
        j = math.gcd(length,k)
        if k == 0:
            return nums
        for i in range(0,j):                        #对于每一个nums[i]以k%length为间隔遍历
            n=1
            a = nums[i]
            while n <= length/j:                    #保证不重复遍历 总次数是length
                q = a                               #临时变量
                a = nums[(i+n*k)%length]
                nums[(i+n*k)%length] = q
                n += 1
        return nums
```