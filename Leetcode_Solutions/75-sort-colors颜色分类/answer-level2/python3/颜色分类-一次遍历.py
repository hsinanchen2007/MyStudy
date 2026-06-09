### 解题思路
python3 一次遍历

使用三个指针，i，j，k，分别指向：
i：从左数第一个不为0的数
j: 从左数第一个不为1的数
k：从右数第一个不为2的数

i <= j <= k

如果j指向的数值为0，则交换i位置与j位置的值
如果j指向的数值为2，则交换j位置与k位置的值

重复这一过程即可，注意边界条件判定。

### 代码

```python3
class Solution:
    def swap(self, nums, i, j):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        t_cur = len(nums) - 1
        z_cur = 0
        o_cur = 0
        while z_cur <= o_cur and o_cur <= t_cur:
            while z_cur < len(nums) and nums[z_cur] == 0:
                z_cur += 1
            while t_cur > 0 and nums[t_cur] == 2:
                t_cur -= 1
            o_cur = z_cur
            while o_cur < len(nums) and nums[o_cur] == 1:
                o_cur += 1
            if o_cur == len(nums) or t_cur == 0 or z_cur == len(nums):
                break
            if o_cur <= t_cur and nums[o_cur] == 2:
                self.swap(nums, o_cur, t_cur)
            elif o_cur >= z_cur and nums[o_cur] == 0:
                self.swap(nums, o_cur, z_cur)

        


```