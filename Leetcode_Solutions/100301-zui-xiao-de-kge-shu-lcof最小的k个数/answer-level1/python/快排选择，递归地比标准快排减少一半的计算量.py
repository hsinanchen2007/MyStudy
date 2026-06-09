### 解题思路
快排的核心思想是取出一个索引值，以这个索引值为分界点把原数组分为左右两个部分。
若左半部分的元素个数正好等于k时，即满足要求。返回数组中前k个数即可。

若左半部分的元素个数大于k时，右半部分不用管，期望从左半部分中再取k个数。
若左半部分的元素个数小于k时，左半部分不用管，期望从右半部分中再取(k-左半部分的元素个数)个数。
这样每次都能递归地比标准快排减少一半的计算量，直到左半部分的元素个数满足要求。

### 代码
```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        def qsort(l,r):
            i=l-1
            for j in range(l,r):
                if arr[j]<=arr[r]:
                    i+=1
                    arr[i],arr[j]=arr[j],arr[i]
            i+=1
            arr[i],arr[r]=arr[r],arr[i]
            return i

        def helper(l,r,k):
            p=qsort(l,r)
            if k<p-l+1:
                helper(l,p-1,k)
            elif k>p-l+1:
                helper(p+1,r,k-(p-l+1))

        if k==0:
            return []
        helper(0,len(arr)-1,k)
        return arr[:k]
```