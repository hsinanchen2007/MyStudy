### 解题思路
一开始求一次整个列表的最大值
遍历，如果该值等于列表最大值，就代表上一次所求的值有可能失效了，重新求列表剩余部分的最大值。
如果不等于就不用管，直接赋值了。

逆序的好处是可以不用一开始求最大值，但同时遍历两个列表、比较两个列表的对应元素的值。
避免了多余的求值，正序效率也不低。

### 代码

```python3
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        maxNum = max(arr)
        for i in range(len(arr)-1):
            if arr[i] == maxNum:    #如果最大值出现，则已失效
                maxNum = max(arr[i+1:])   #重新求最大值
            arr[i]=maxNum                 #其余时候直接赋值
        arr[-1]=-1
        return arr
```