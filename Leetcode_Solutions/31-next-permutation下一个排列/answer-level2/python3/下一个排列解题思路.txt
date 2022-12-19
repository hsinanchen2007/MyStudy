### 解题思路
分析"下一个排列题意"会发现：*总是将某个**大一点的数字**与前面某一个**小一点的数字**进行交换*，那么**1.需要从后往前找**，
如何找到这两个数，分析一些排列会发现总会**2.存在一个升序两个数的序列**（这就是需要找到的数），**若不存在：则无下一个排列**，**3.将小一点的数与其后面比它大一点的数进行交换**， **4.对小一点的数后面进行升序排列即可**

建议：可以自己写一下1 2 3 4的排列来进行分析，或根据别人提供的思路用该排列来进行分析



### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 思考思路：从右向左找到第一对升序数列a[i-1] a[i]，找到a[i-1]右边较大的数a[j]，
        # 交换a[i-1] a[j] ,将a[i-1]右侧的数进行升序排列
        flag = 0  # 标记是否存在下一个排列
        for i in range(len(nums)-1, 0, -1):
            if nums[i] > nums[i-1]:
                flag = 1  # 存在下一个排列
                j = i
                dis = 9.9e50
                p = -1
                while j <= len(nums)-1:
                    if nums[j] > nums[i-1] and abs(nums[j] - nums[i-1]) < dis:
                        p = j
                        dis = abs(nums[j] - nums[i-1])
                    j += 1 
                # 交换a[i-1] a[p]
                temp = nums[i-1]
                nums[i-1] = nums[p]
                nums[p] = temp
                # a[i-1]右边升序
                t = nums[i:]
                t.sort()
                nums[i:] = t
                break
        if flag == 0:  # 不存在下一个排列
            nums.sort()
```