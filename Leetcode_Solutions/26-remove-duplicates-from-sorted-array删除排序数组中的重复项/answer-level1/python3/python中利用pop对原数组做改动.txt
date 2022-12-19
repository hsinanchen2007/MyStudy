### 解题思路
python删除list中元素的三种方法：
1、a.pop(index): 删除列表a中index处的值,并且返回这个值.
2、del(a[index]): 删除列表a中index处的值,无返回值. del中的index可以是切片,所以可以实现批量删除.
3、a.remove(value): 删除列表a中第一个等于value的值,无返回.
用remove时效率低，用时长，这里选择用pop方法。

假如从前往后正向遍历数组，做删除操作时索引会变，所以可以从后往前，解决索引改变的问题。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums)-1, 0, -1):
            if nums[i] == nums[i-1]:
                nums.pop(i)
        return len(nums)
```