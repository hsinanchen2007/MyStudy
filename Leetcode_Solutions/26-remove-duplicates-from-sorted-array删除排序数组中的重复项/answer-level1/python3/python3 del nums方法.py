
代码思路：
既然不能正着删除list元素，因为会造成list长度错误，所以从末尾开始判断，然后删除相同元素


代码块
```import sys
import math
import numpy as np
from gettext import find
from typing import List
from numpy.core.fromnumeric import sort
from nt import remove

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums))[::-1]:
            if i-1 != -1:
                if nums[i-1] == nums[i]:
                    del nums[i] 
        return len(nums)

def main():
    n = [1]
    a=Solution()
    print(Solution.removeDuplicates(a,n))

if __name__ == '__main__':
    main()
