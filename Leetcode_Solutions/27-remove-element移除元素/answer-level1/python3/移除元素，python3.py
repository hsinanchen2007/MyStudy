class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        flag = 0
        for num in nums:
            if num != val:
                nums[flag] = num
                flag += 1

        return flag

根据上一题的思路做的 36 ms
![SharedScreenshot1.jpg](https://pic.leetcode-cn.com/e7ce03f2b363bb7a50723591b5cd38cd9be400042a025785c48b253e2c794055-SharedScreenshot1.jpg)
