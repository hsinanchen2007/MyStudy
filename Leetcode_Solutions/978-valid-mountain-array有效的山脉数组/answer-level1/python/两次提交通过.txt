1. 如果数组长度小于3，返回False
2. 找到数组最大值位置l,如果最大值在数组最外侧，返回False
   如果不在最外侧，分别顺序比较最大值左、右侧的值。
   左侧：从0位开始向右比较，如果大于下一个位置的值，返回False;直至比较到l-1位
   右侧：从l位开始向右比较，如果小于或等于下一个位置的值，返回False;直至比较到len(A)-1位
3. 其他情况返回 True

```
class Solution(object):
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if len(A) < 3:
            return False
        
        # 所谓山脉数组，即在数组中存在一个元素，左右两侧的元素都比它小
        # 从右向左遍历，比较第i-1个元素，与第i-2个元素，如果小于，则继续
        
        l = A.index(max(A))        
        if l == 0 or l == len(A)-1:
            return False
        else:
            for i in range(l-1):
                if A[i] > A[i+1]:
                    return False
            for i in range(l, len(A)-1):
                if A[i] <= A[i+1]:
                    return False        
        return True
```
