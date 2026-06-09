解题思路：
已知arr2是不重复的列表，所以将它用来循环，借助第三方，即再创一个list3来完成排序。
第一层循环是先排arr1中与arr2中**重复**的部分，统计出arr2中元素在arr1中的对应个数，然后
开始一个新的循环，在list3中加入相应个数的元素，同时在arr1中删除相应个数的元素。
结束两层循环后，arr1中剩余的则是其**独有**的元素，对其进行排序，然后全部加入list3的末尾。
此时list3满足题解要求。

```
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        length=len(arr2)
        list3=[]
        for i in range(length):
            n=arr1.count(arr2[i])
            for j in range(n):
                list3.append(arr2[i])
                arr1.remove(arr2[i])
        arr1.sort()
        list3=list3+arr1
        return list3
```


