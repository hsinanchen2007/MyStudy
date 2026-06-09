```
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res=[]
        temp=[]
        for x in arr2:
            num=arr1.count(x)
            res+=[x]*num
        for x in arr1:
            if x not in arr2:
                temp.append(x)
        #return res.extend(temp.sort())
        #return res.extend(sorted(temp))

        res.extend(sorted(temp))
        return res

        """
        #注释处是错误写法
extend方法没有返回值，但会在已存在的列表中添加新的列表内容。
sort()也没有返回值，sorted()有返回值
        sort 与 sorted 区别：

sort 是应用在 list 上的方法，sorted 可以对所有可迭代的对象进行排序操作。

list 的 sort 方法返回的是对已经存在的列表进行操作，无返回值，而内建函数 sorted 方法返回的是一个新的 list，而不是在原来的基础上进行的操作。



        """
```
