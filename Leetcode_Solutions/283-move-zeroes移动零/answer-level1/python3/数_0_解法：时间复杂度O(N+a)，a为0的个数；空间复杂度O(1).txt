题目不难。但是要在原地操作的基础上，尽量减少操作次数就值得思考了。

# 一、解题思路
观察题目，会发现：**输出的结果中，每个非零数字对应的位置序号(index)，只可能小于等于输入结果中对应的序号(index_old)。**

那么我们可以先将**非零数字**找出来依次排到数组前列，并**记录排列的次数**；对于原数组中的"**0**"，仅需要**计数**即可，最后统一赋值根据排列非零数字的次数，**统一赋值在非零数字后面**。

# 二、具体做法（Python3）
我这里采用数"0"的方法来解题。

遍历数组nums，这里有两种情况：
1. 遇到不为"0"的数，将它们依次找出来，并依次赋值给nums[i]，并且i+=1
2. 遇到为"0"的数：每遇到一个，计数器cnt加1，i不变
3. 最后，nums[:i]为原数组中所有的非零数，nums[i:]全部为"0"即可

# 三、代码（Python3）
附上代码：
``` python []
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, cnt = 0, 0
        for num in nums:
            if 0 != num:
                nums[i] = num
                i+=1
            else:
                pass
        
        for i in range(i, len(nums)):
            nums[i] = 0
```

