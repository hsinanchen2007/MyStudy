### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findSpecialInteger(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        # #1.哈希表
        # h = {}
        # if len(arr) == 1 : return arr[0]
        # for i in arr :
        #     if i not in h :
        #         h[i] = 1
        #     else :
        #         if h[i] >= len(arr) / 4 :
        #             return i
        #         else :
        #             h[i] += 1
        

        #2.双指针遍历
        i, j = 0, len(arr) / 4
        while j < len(arr) :
            if arr[i] == arr[j] : return arr[i]
            else : 
                i += 1
                j += 1
        
            
        
```