![df.jpg.png](https://pic.leetcode-cn.com/8d9869f15159495ccd29a482b68bfd8b2e498180d36b4017117b8538d23e32c9-df.jpg.png)
```
class Solution(object):
    def addNegabinary(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        d = []
        if arr1 == [0]:
            sum1 = 0
        else:
            sum1 = 0
            for i in range(len(arr1)):
                if arr1[i] == 1:
                    sum1 = sum1 + (-2) ** (len(arr1) - 1 - i) 
        if arr2 == [0]:
            sum2 = 0
        else:
            sum2 = 0
            for i in range(len(arr2)):
                if arr2[i] == 1:
                    sum2 = sum2 + (-2) ** (len(arr2) - 1 - i)
        c = sum1 + sum2
        if c == 0:
            return [0]
        while c:
            if c % -2 != 0:
                d = [1] + d
                c = (c // -2 ) + 1
            else:
                d = [0] + d
                c = c // -2
        return d
```
