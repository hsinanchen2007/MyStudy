```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums or not k % len(nums):
            return nums

        self._rotate1(nums, k % len(nums))

    def _rotate1(self, nums, k):
        """
        利用tmp变量来存储需要覆盖到k位以后的值，然后为了避免出现len(nums) = 4, k = 2这类情况时出现的死循环
        所以设置交换次数计数器swap_count来跳出循环。
        """
        cur_posi, swap_time = 0, 0

        while swap_time < len(nums):
            # 初始赋值等于一次交换，不然应该从posi = cur_posi开始计算。
            tmp, posi, swap_time = nums[cur_posi], (cur_posi + k) % len(nums), swap_time + 1

            # 等循环遍历完一遍，会回到起始点。
            while posi != cur_posi:
                nums[posi], tmp = tmp, nums[posi]
                posi, swap_time = (posi + k) % len(nums), swap_time + 1

            nums[cur_posi], cur_posi = tmp, cur_posi + 1

    def _rotate2(self, nums, k):
        def _reverse(i, j):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i + 1, j - 1
        
        _reverse(0, len(nums) - 1)
        _reverse(0, k- 1)
        _reverse(k, len(nums) - 1)

    # 暴力超时
    def _rotate3(self, nums, k):
        for _ in range(k):
            tmp = nums[-1]
            for i in range(len(nums)):
                nums[i], tmp = tmp, nums[i]
```