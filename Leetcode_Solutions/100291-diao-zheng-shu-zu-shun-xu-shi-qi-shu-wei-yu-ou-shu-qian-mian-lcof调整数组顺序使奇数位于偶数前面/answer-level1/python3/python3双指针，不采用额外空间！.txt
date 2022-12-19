# 设置两个左右指针，分别代表左右边界的奇偶
**共有四种情况：**
1.同为奇数：右边界不变，左边界右移。右边界等待左边界出现偶数来与其交换。
2.同为偶数：左边界不变，右边界左移。左边界等待右边界出现奇数来与其交换。
3.左奇右偶：都往里移动一步。
4.左偶右奇：交换两者位置，都往里移动一步。
最后返回改变后的数组即可！

```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        i,j=0,len(nums)-1
        while i<j:
            if nums[i]%2==0 and nums[j]%2==1:
                nums[i],nums[j]=nums[j],nums[i]
                i+=1
                j-=1
            elif nums[i]%2==1 and nums[j]%2==0:
                i+=1
                j-=1
            elif nums[i]%2==0 and nums[j]%2==0:
                j-=1
            else:
                i+=1
        return nums
```
# 复杂度分析
**1. 时间复杂度：O(N)。
2. 空间复杂度：O(1)。**

