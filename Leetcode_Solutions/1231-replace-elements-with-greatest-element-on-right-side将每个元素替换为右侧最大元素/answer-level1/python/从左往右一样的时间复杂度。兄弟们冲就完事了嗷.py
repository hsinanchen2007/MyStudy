### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def replaceElements(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        pre=0
        now=0
        if len(arr)<2:
            arr[0]=-1
            return arr
        while now<len(arr)-1:
            maxnum=max(arr[pre+1:])
            now=arr[pre+1:].index(maxnum)+pre+1
            for i in range(pre,now):
                arr[i]=maxnum
            # print(pre,now)
            pre=now
        arr[-1]=-1
        return arr
```