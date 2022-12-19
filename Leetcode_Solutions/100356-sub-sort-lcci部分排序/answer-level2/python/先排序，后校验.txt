### 解题思路
总感觉这个题好像在leetcode正题里出现过了

### 代码

```python
class Solution(object):
    def subSort(self, array):
        """
        :type array: List[int]
        :rtype: List[int]
        """
        #好像做过了
        sortarray=sorted(array)
        if sortarray==array:
            return [-1,-1]
        else:
            l,r=0,len(array)-1
            while array[l]==sortarray[l]:
                l+=1
            while array[r]==sortarray[r]:
                r-=1
        return [l,r]
```