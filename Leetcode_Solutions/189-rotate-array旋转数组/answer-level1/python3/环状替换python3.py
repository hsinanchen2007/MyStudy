```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        思路一：暴力法。 超时
        """
        # for i in range(k):
        #     tmp = nums[len(nums) - 1]
        #     for j in range(len(nums) - 2, -1, -1):
        #         nums[j + 1] = nums[j]
        #     nums[0] = tmp

        # n = len(nums)
        # for i in range(k):
        #     pre = nums[n - 1]
        #     for j in range(n):
        #         tmp = pre
        #         pre = nums[j]
        #         nums[j] = tmp
        '''
        思路二：定义额外数组。 空间复杂度O(n)
        '''
        # n = len(nums)
        # tmp = [0] * n
        # for i in range(n):
        #     tmp[(i + k) % n] = nums[i]
        # for i in range(n):
        #     nums[i] = tmp[i]
        '''
        思路三：环状替换。   从start开始，寻找最终位置 (pos + k) % n ，逐个与 nums[start] 替换；
                            当出现 闭环，即交换后值的最终目标位置恰为 start，则该轮完毕，将 start + 1，继续替换。
                            因为每个数的移动间隔固定，所以不会冲突，且每个数都需替换一次
                            故 时间复杂度 O(n)，空间复杂度O(1)
        '''
        # n = len(nums)
        # pos = k % n # 初始(0 + k)%n
        # start = 0
        # status = False #标记是否 成环，若成环，将起始位置后移
        # if k==0:
        #     return
        # for j in range(n):
        #     #若 status == True, 说明上一轮交换后都各自归位，无需替换；并将起点后移
        #     if status == True:
        #         start += 1
        #         pos = start
        #     else:
        #         tmp = nums[start]
        #         nums[start] = nums[pos]
        #         nums[pos] = tmp
        #     pos = (pos + k) % n
        #     # 下一轮的目标pos == start
        #     if pos == start:
        #         status = True
        #     else:
        #         status = False

```
