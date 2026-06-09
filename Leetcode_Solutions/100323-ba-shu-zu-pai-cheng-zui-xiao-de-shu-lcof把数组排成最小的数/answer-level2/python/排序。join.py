### 解题思路
构造cmp，join

### 代码

```python
class Solution(object):
    def minNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """

        nums=[str(x) for x in nums]
        def compare(a,b):
            if a+b>=b+a:
                return 1
            else:
                return -1
                    

        # print compare('3','30')
        # print compare('4','5')
        nums= sorted(nums,cmp=compare)
        print nums

        result=''.join(nums)
        return result
```