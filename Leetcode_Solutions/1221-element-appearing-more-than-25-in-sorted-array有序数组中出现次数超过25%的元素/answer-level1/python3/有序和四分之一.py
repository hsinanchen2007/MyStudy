### 解题思路
因为是有序，如果四分之一长度后还出现，那么就是了

### 代码

```python3
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        # 最开始写的这个思路最垃圾了
        # length = len(arr)
        # i = 0
        # my_dict = {}
        # while True:
        #     if my_dict.get(arr[i]) == None:
        #         my_dict[arr[i]] = 1
        #         if arr.count(arr[i]) > length/4:
        #             return arr[i]
        #     i = i + 1
        # 在这用到有序和四分之一这个条件
        length = int(len(arr)/4)
        i = 0
        while True:
            if arr[i] == arr[i + length]:
                return arr[i]
            i = i + 1
             

                


```