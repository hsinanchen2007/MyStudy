思路是像冒泡一样把最大的数往后边移动
可以先把最大的数交换到首部，再对整个序列反转
需要做n次递归，每次调用递归查找最大值，时间复杂度o(n2)

```
import numpy
class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        #思路：对每一个子列表，将最大的数排到最后面
        def reverse_list(a_list,k):
            #对列表的k位置进行反转
            b = a_list[0:k+1][::-1]
            return b + a_list[k+1:]
        res = []
        def max_last(a_list):
            if len(a_list) == 1:
                return
            max_idx = numpy.argmax(a_list)
            if max_idx != len(a_list) -1:
                a_list = reverse_list(a_list,max_idx)
                if max_idx !=  0:
                    res.append(max_idx+1)
                a_list = reverse_list(a_list,len(a_list)-1)
                res.append(len(a_list))
            max_last(a_list[0:len(a_list)-1])
        max_last(A)
        return res
```
