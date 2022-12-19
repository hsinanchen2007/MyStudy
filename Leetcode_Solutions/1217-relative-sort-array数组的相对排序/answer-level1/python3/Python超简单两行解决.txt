根据array2创建一个{value: index}索引字典
利用python sorted中按key排序的方法，将array1中的元素按照字典排序。有个小技巧是不在array2中的元素可以返回1000+自身的值，这样它们就会被放在最后并按升序排列。
```
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        d = {v:k for k,v in enumerate(arr2)}
        return sorted(arr1, key=lambda x:d.get(x,1000+x))

```
