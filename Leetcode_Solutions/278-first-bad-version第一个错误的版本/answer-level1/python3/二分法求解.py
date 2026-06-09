### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/caeabc84e495143bac7a2727bc408729787782821248e8be5b7d6b0325fd6781-image.png)

### 代码

```python
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left,right=1,n
        while left<right:
            mid=left+(right-left)//2
            if isBadVersion(mid):
                right=mid
            else:
                left=mid+1
        return right
```