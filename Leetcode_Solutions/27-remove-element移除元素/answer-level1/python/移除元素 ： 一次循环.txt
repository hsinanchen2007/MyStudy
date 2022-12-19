### 解题思路
> 执行用时 :
12 ms, 在所有 Python 提交中击败了98.79%的用户
内存消耗 :11.7 MB, 在所有 Python 提交中击败了78.27%的用户

---

> 
如有数组```[0,1,2,2,3,0,4,2]```，为保证相同元素密集，因此对此排序依次
得：    ```[0,0,1,2,2,2,3,4]```
```val = 2```
我们通过一个头标，一个尾标来遍历数组，
结束条件是头标越过尾标
通过头标移动，依次对0，0,1做判断，都不是2，此时头标到了3，尾标未动
找到一个2，则将尾标指向的4移动到当前2的位置， 尾标移动一格指向3，头标指向4
此时元素为```0,0,1,4,2,2,3,4```
重复上面动作，头标4跟2判断，不相等，继续后移指向2
2等于目标数字，把尾标的3移动到当前位置，
此时元素为```0，0，1，4，3，2，3，4```
继续移动，当头标越过尾标停止，此时0->头标 就是排除所有2元素的新数组，头标大小就是个数
### 代码

```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if not nums:
            return 0
        nums.sort()
        length = 0
        numLen = len(nums)
        lastLen = numLen - 1
        while length <= lastLen:
            if nums[length] != val:
                length = length + 1
            else:
                nums[length] = nums[lastLen]
                lastLen = lastLen - 1
        return length

```