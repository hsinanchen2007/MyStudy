### 解题思路
1.将去重的列表存到一个新列表中
2.对新列表排序
3.遍历列表并将新列表的值赋到nums中
4.返回去重后的列表长度

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        a = list(set(nums))#将去重的列表存到一个新列表中
        a.sort()#对新列表排序
        for i in range(len(a)):#遍历列表并将新列表的值赋到nums中
            nums[i] = a[i]
        return len(a)#返回去重后的列表长度
```