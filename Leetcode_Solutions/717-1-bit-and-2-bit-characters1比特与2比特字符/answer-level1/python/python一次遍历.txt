### 解题思路
![image.png](https://pic.leetcode-cn.com/ba32d622f82a981af19ff466ac8ed5a8b6cec12f71be547f1fd99584fdfff2dd-image.png)

### 代码

```python
class Solution(object):
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        p=0
        while p<len(bits):
            if bits[p]==0 and p!=len(bits)-1:
                p+=1
            elif bits[p]==1:
                p+=2
            elif bits[p]==0 and p==len(bits)-1:
                return True
        
        return p!=len(bits)
```