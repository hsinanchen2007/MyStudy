### 解题思路
1. 首先先排序。
2. 两两相减的差以及数组放到列表中，例如：
    `[[[1,2],1], [[2,3],1], [[3,5],2]]....`
3. 并记录下最小差值。
4. 定义一个函数，用来查找以上列表中，差值等于最小差值的数组。

### 代码

```
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        idx = 1
        total = []
        min_minus = 10^7
        while idx < len(arr):
            nums = []
            corresponding = []

            nums.append(arr[idx-1])
            nums.append(arr[idx])
            
            minus = abs(arr[idx]-arr[idx-1])
            corresponding.append(nums)
            corresponding.append(minus)
            total.append(corresponding)
            min_minus = min(min_minus, minus)
            idx += 1
        
        def find_corresponding(corresponding_list):
            abs_min = []
            for item in corresponding_list:
                if item[1] == min_minus:
                    abs_min.append(item[0])
            return abs_min
        
        return find_corresponding(total)


```