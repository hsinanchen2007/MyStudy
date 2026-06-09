双指针法来运算，不用考虑中间数组

```
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        sumvalue = 0

        for i in A:
            sumvalue += i

        #初次判断列表成员和能不能被3整除，不能则说明不能分成3份
        if sumvalue % 3 != 0:
            return False
        
        #求出能分3份时，每份的值
        value = sumvalue // 3
        
        #以下时双指针法：计算从前向后遍历时，累加和等于value时，最后一个索引值
        lenA = len(A)
        tmp = 0
        for start_index in range(lenA):
            tmp += A[start_index]
            if tmp == value:
                break
        #print start_index, value 

        #计算从后向前遍历时，累加和等于value时，最后的一个索引值
        tmp = 0
        for end_index in range(lenA)[::-1]:
            tmp += A[end_index]
            if tmp == value:
                break
        #print end_index, value

        #如果从前往后的索引值小于从后往前的索引值，并且两个索引值不相邻，则正确
        return True if start_index + 1 < end_index else False
```
