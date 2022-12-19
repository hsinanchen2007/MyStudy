### 解题思路
此处撰写解题思路
相对顺序排序，就是arr2的元素是相对顺序排序，其他剩下在arr1的元素是正常排序，然后就是hash，找到个数，就可以了。下面的代码写的比较简洁，可以参考
题目意思其实不明确，也是测试了一些case才体会出来题目意思的。
### 代码

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        dic = collections.Counter(arr1)
        ans = []
        for i in arr2:
            ans.extend([i]*dic[i])
            dic.pop(i)
        temp = []
        for k,v in dic.items():
            temp.extend([k]*v)
        temp.sort()
        ans.extend(temp)
        return ans

        
```