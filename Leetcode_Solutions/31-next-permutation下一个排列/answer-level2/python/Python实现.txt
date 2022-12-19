### 解题思路
这道题的思路其实不难，可能讲起来不太好讲。
对于一个数nums，如果它存在下一个序列，那么我们应该尽量在低位进行调整（改变顺序）而高位不变，比如[1, 2, 3, 4, 5]，如果我们改变低两位，则是[1, 2, 3, 5, 4]，改变低三位，则是[1, 2, 4, 3, 5]，显然只改变后两位是正确答案。当我们确定了这一准则后，问题就变成我们如何确定开始调整的位，即对于[1, 2, 3, 4, 5]如何确定从nums[3]开始调整。如果确定的位开始可以进行调整，那么这一确定的位调整后的数字大小一定大于原始的数字（如果调整后不变，则说明不是从这一位开始调整），再把问题抽象一下，如果我们从第i位调整序列，那么第i位后一定存在第j位的数字nums[j] > nums[i]，那么这就是我们确定位置的条件，我们把刚好大于nums[i]的nums[j]对nums[i]进行替换，而剩下的nums[i + 1:]则只需要从小到大进行排序即可。
对于具体实现方面：当我们发现任意nums[j] <= nums[i] (j > i)，那么我们对nums[i:]进行升序排序，这么做有两个好处，一是方便后续确定是否存在nums[j] > nums[i]，另一方面对于不存在下一个更大的序列时不需要进行特判，退出循环时序列正好是升序的。
ps: 我已经尽力想讲清楚实现方法，但是肯定有相当一部分人没看明白，那么各位可以用以下代码自行构建序列，然后输出每次循环后的序列，这样可以方便理解具体思路。

### 代码

```python
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        if length == 1:
            return 
        for i in range(length - 2, -1, -1):
            j = i + 1
            while j < length and nums[j] <= nums[i]: # 这个等号必须取到
                j += 1
            if j == length: # 直接插到最后
                temp = nums[i]
                nums[i:length - 1] = nums[i + 1:]
                nums[length - 1] = temp
            else: # 只需要交换i和j对应位置的元素
                temp = nums[i]
                nums[i] = nums[j]
                nums[j] = temp
                break
```