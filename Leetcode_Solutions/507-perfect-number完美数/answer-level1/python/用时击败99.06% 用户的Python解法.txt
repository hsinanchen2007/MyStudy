### 解题思路

数学家欧拉曾推算出完全数的获得公式：如果p是质数，且2^p-1也是质数，那么（2^p-1）X2^（p-1）便是一个完全数。根据这一公式，如果一个数是完全数，则它可以表示为（2^p-1）X2^（p-1）的形式，其中p为质数。


### 代码

```python
class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        # Pefect number 
        if num <= 0:
            return False
        elif num % 2 != 0:
            return False
        else:
            for i in [1,2,3,5,7,11,13,17,23,29,31]:
                tmp1 = 2 ** i
                tmp2 = 2 ** (i - 1)
                if tmp1 * tmp2 - tmp2  == num:
                    return True
                    break
            return False
        #执行用时 :12 ms, 在所有 Python 提交中击败了99.06% 的用户
        #内存消耗 :11.7 MB, 在所有 Python 提交中击败了69.62%的用户



```