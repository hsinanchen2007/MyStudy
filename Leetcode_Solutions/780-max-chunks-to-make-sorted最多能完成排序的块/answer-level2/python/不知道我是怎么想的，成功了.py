遇见最小的数，块就加一；
遇见到当前为止最大的数，看此时的数组下标是否等于这个数，等于就更新最小的数为下标加1
代码如下
```
class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        res=0
        small=0
        big=arr[0]
        for i in range(len(arr)):
            if arr[i]==small:
                res+=1
            if arr[i]>=big:
                big=arr[i]
            if big==i:
                small=i+1
        return res
```