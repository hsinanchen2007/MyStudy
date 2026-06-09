```
class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        l = len(arr)
        # 从后往前插0，不会影响遍历时的下标
        for i in range(l-1,-1,-1):
            if arr[i] == 0:
                arr.insert(i+1,0)
        
        # 将数组的长度恢复
        for i in range(len(arr)-l):
            arr.pop()
```
