### 解题思路
此处撰写解题思路
通过快速排序将给的列表从小到大排好，再从中取出前k个即可
### 代码

```python3
class Solution:
    def quick_sort(self,data_list):
        if len(data_list) >= 2:
            left,right = [],[]
            mid_num = data_list[len(data_list)//2]
            data_list.remove(mid_num)
            for num in data_list:
                if num > mid_num:
                    right.append(num)
                else:
                    left.append(num)
            return self.quick_sort(left) + [mid_num] + self.quick_sort(right)
        else:
            return data_list
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if len(arr) == 0:
            return None
        elif len(arr) == 1:
            return arr[0]
        else:
            arr_sort = self.quick_sort(arr)
            return arr_sort[:k]
```