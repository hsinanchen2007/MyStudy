采用双指针算法中的对撞指针解决该问题：
  看到这个题目首先想到的是用暴力解法（双层遍历）来解决该问题，当然肯定能够想到答案的时间复杂度高，为O（n^2），当输入暴力解法之后显示的是17个输入有16个输入通过，估计是自己的答案有误，因此采用对撞指针来进行求解，其复杂度为O(nlogn)。
  对撞指针：首先指定左右指针i和j，左右指针分别往右和往左进行移动，因为是有序数组，所以当两指针对应的数组值小于目标值时，左指针右移，当大于目标值时，右指针左移，大致思路如此。

### 代码

```python
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        i,j=0,len(numbers)-1
        while i<j:
            if numbers[i]+numbers[j]==target:
                break
            elif numbers[i]+numbers[j]<target:
                i+=1
            else:
                j-=1
        return [i+1,j+1]

```