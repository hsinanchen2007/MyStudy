```
代码块
```

    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1.sort() #先排序 为后续添加不存在的元素做准备
        res=[]
        for i in arr2: #计算排序
            count=arr1.count(i)
            for j in range(count):
                res.append(i)
                
        for i in arr1: #添加没有的元素
            if i not in arr2:
                res.append(i)
        return res