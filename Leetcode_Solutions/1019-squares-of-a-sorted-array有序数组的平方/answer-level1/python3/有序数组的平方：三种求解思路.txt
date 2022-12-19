可以使用python内置的排序函数。也可以使用双指针，逆序遍历负数部分，正序遍历非负数部分
在使用双指针方法时，要注意如何得到负数与非负数的界限，使用 j = i+1 很有可能会越界，导致错误
```vim
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        """1. 使用内置的排序函数"""
        result = [x*x for x in A]
        return sorted(result)
        
        """2. 使用双指针的思想
            负数部分从后向前遍历，非负数部分向后遍历
        """
        """这种获取负数与非负数界限的方法有问题
         i, j = 0, 0  # i 是遍历负数部分的指针，j 是遍历非负数部分的指针
        for index in range(len(A)):
            i = index
            j = index
            if A[i] < 0 and A[j+1] >=0:
                break
        j = j+1
        """
    
        j = 0
        while j < len(A) and A[j]<0:
            j += 1
        i = j-1

        result = []
        while i >= 0 and j <= len(A) - 1:
            tempj = A[j] * A[j]
            tempi = A[i] * A[i]
            if tempi <= tempj:
                result.append(tempi)
                i -= 1
            elif tempi > tempj:
                result.append(tempj)
                j += 1

        if i < 0 and j > len(A) - 1:
             pass
        elif i < 0 and j <= len(A) - 1:
            for index in range(j, len(A)):
                result.append(A[index] * A[index])
        elif i >= 0 and j > len(A) - 1:
            for index in range(i, -1, -1):
                result.append(A[index] * A[index])
                
        return result

        """3. 先对原始数组进行排序"""
        return [x*x for x in sorted(A, key=lambda a:abs(a))]
```
