### 解题思路
0401

### 代码

```python3
class Solution:
    def findSpecialInteger(self, arr):
        length=len(arr)
        if length==1:
            return arr[0]
        else:
            for i in arr:
                num=arr.count(i)
                if(length/num<4):
                    return i
```
