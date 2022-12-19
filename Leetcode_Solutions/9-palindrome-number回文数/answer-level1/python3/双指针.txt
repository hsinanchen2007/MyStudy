### 解题思路
双指针，时间复杂度O(n)

### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        list1 = list(str(x))
        n = len(list1)
        l = 0
        r = n-1
        if x < 0:
            return False
        if n == 1:
            return True
        
        for i in range(len(list1)/2):
            if list1[l] == list1[r] and l <= r:
                l += 1
                r -= 1
            else:
                return False
        return True
                    
        
                    

                

```