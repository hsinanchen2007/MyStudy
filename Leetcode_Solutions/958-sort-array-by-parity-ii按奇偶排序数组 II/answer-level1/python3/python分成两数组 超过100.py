思路很简单
先把原先数组分成两个子数组
然后每次分别从子数组取一个出来   放入新数组里 时间超过100 空间超过99
```
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        #divide into two array
        length = len(A)
        odd_list = []
        even_list = []
        for i in A:
            if i % 2 == 0:
                even_list.append(i)
            else:
                odd_list.append(i)
        output = []
        n = len(even_list)
        for i in range(0,n):
            #put the elements in the new array in order
            output.append(even_list[i])
            output.append(odd_list[i])
        return output

```
