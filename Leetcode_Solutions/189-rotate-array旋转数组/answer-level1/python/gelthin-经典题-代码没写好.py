
### 解题思路
同习题 [面试题58 - II. 左旋转字符串](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

Huangyu 老师课上介绍过此题。

各种方法如下:
+ 暴力每个人平移 1 位， 重复 k 次。
+ 反转法， 先反转整个数组，然后反转两个部分。这有点像 “翻转烧饼” 题。
+ 轮换法，一步到位。 不过编码有技巧

大四投过一次华为，做过一次华为的机试题。 当时用的是分治递归，每次数组规模降低 1.

#### 轮换法
轮换法当 n%k == 0 时，实际上要重启动 k 次。
当 gcd(n, k) == 1 时， 只需任意找一个点，启动一次即可。若 gcd(n, k) != 1, 实际上也需要重启多次。
例如 n=6, k = 4， 需要重启两次。 

这里写代码也比较难写，python 无法实现 do while 循环。用一个 count 变量来调整循环是否结束。


### 反转法代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # huangyu 老师课上题目。黄老师的思路是反转。 过了这么久我也忘记了。
        n = len(nums)
        k = k%n    # 避免特例报错 [1], 2 下面下标超界报错
        
        # 反转整个数组 
        i, j = 0, n-1
        while i<j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        
        # 反转前一半    
        i, j = 0, k-1
        while i<j and j<n:
            nums[i], nums[j] = nums[j], nums[i]  # 这里对 [1] 2 可能会报错。
            i += 1
            j -= 1
        # 反转后一半
        i, j = k, n-1
        while i<j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

        return nums
```