首先将所有元素和x相减之后的绝对值保留在数组Abs中，然后再对其进行排序得到数组sub，再找到sub的前k个元素在Abs中的索引值，那么这k个索引值就是最接近元素在arr中的索引，将其添加到一个新的数组中返回即可。
```
```
class Solution(object):
    def findClosestElements(self,arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        my_list=[]
        n=len(arr)
        Abs = []
        for i in range(n):
            if arr[i] < x:
                Abs.append(x - arr[i])
            else:
                Abs.append(arr[i] - x)
        # print(Abs)
        sub = sorted(Abs)
        # print(Abs,sub)
        Index = []
        for i in range(k):
            number = Abs.index(sub[i])
            Abs[number] = 'None'
            Index.append(number)
        # print(Index)
        for i in Index:
            my_list.append(arr[i])
        # print(my_list)
        return sorted(my_list)
```

```

