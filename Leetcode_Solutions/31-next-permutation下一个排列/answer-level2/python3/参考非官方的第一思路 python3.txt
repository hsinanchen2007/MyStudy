![image.png](https://pic.leetcode-cn.com/f743608d7c1ad9714322be26ed5235f46be39a9c5f6fc9a669529c6a23cd8eda-image.png)


```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        for i in range(len(nums)-2, -1, -1):
            if nums[i] >= nums[i + 1]:
                continue
            else:
                for j in range(len(nums) - 1, i, -1):
                    if nums[j] <= nums[i]:
                        continue
                    else:
                        tmp = nums[i]
                        nums[i] = nums[j]
                        nums[j] = tmp

                        # 然后对剩下的逆序
                        for k in range((len(nums) - i - 1)//2):
                            tmp = nums[i + 1 + k]
                            nums[i + 1 + k] = nums[-1 - k]
                            nums[-1 - k] = tmp
                        return
        # 如果上面的for循环走完都没有return，就对整个nums逆序
        # 注：直接nums = nums[::-1]无效（返回值还是原始nums），估计是禁用了额外非常数空间，只能用for循环
        for k in range(len(nums) // 2):
            tmp = nums[k]
            nums[k] = nums[-1 - k]
            nums[-1 - k] = tmp
        return

```
