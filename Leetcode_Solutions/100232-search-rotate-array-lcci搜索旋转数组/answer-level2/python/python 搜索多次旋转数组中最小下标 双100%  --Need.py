### 充满迷惑的面试题，同时又与常规题做了拓展
1. 搜索**多次**旋转数组中**最小下标**
    - 本题不同于 **搜索旋转数组**  存在两点
    - 一，“多次”，这是一道烟幕弹，对解题没有任何影响
    - 二，“最小下标”，这是需要额外注意的：存在重复元素，需要找出最左侧的数字：**即当arr[mid] == target，需要判断mid左侧是否还有target存在**

![LC.png](https://pic.leetcode-cn.com/3f424f2854cf14d187f523d4f487740e49e9e4e92c48cbb260dea0a1630c9653-LC.png)


2. 10分钟内AC，且双100%，小小高兴一把！



### 代码

```python3
class Solution:
    def search(self, arr: List[int], target: int) -> int:
        nsize = len(arr)
        if nsize < 1:
            return -1
        
        return self.binary_search(arr, 0, nsize-1, target)
    

    def binary_search(self, arr, l, h, target):
        if l > h:
            return -1
        mid = (l + h) // 2
        if arr[mid] == target:
            lmid = self.binary_search(arr, l, mid-1, target)
            return mid if lmid == -1 else lmid 
        
        if arr[mid] <= arr[h]: # ordered [mid:h]
            if arr[mid] < target and arr[h] >= target:
                return self.binary_search(arr, mid+1, h, target)
            else:
                return self.binary_search(arr, l, mid-1, target)
        else: # ordered [l, mid]
            if arr[l] <= target and arr[mid] > target:
                return self.binary_search(arr, l, mid-1, target)
            else:
                return self.binary_search(arr, mid+1, h, target)
        
```