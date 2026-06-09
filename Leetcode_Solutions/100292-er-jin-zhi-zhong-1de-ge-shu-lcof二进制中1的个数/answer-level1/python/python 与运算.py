### 解题思路
n中最低位的1总是对应着n-1中的0，将n与n-1进行与运算（&），就可以将n中最低位的1变为0，使用while循环，统计1的数量

### 代码

```python
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans=0
        while n !=0:
            ans+=1
            n=n&(n-1)
        return ans

```