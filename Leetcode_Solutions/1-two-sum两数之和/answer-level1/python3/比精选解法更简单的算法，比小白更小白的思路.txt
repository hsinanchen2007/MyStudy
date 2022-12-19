1. 抓住两个关键点：返回下坐标，不能重复利用同样元素；
2. 返回下坐标则直接想到用枚举
3. 不能重复利用元素则要求能形成TARGET的两个整数不能拥有同一个下标
4. 三行代码解决问题


def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i, n in enumerate(nums):
            if target-n in nums and nums.index(target - n) != i:
                return nums.index(target - n), i