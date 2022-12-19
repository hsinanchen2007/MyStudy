因为arr2中元素在arr1中都有，所以可以在arr2数组上操作
遍历arr1，数每出现一次就在字典中值+1，这样值>1，就说明出现了两次以上，需要在arr2中添加了。
添加的时候需要找到arr2中这个数字的位置，然后插入，这里应该挺耗时间。
对了，如果arr1中的数arr2中没有，单独建列表好了，最后排序后加到arr2中就好。(没审题还错了一次)
就是这样了。

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        times = dict(zip(arr2,[0 for _ in range(len(arr2))]))
        new = []
        for i in arr1:
            if i not in arr2:
                new.append(i)
            else:
                times[i] += 1
                if times[i]>1:
                    here = arr2.index(i)
                    arr2.insert(here,i)
        return arr2+sorted(new)


```