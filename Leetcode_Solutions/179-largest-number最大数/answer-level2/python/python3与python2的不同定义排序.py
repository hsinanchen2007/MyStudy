思路：直接拼接数字，可能导致数值溢出，这是一个隐形的大数问题，需要把数字转换成字符串。然后需要定义一种比较两个数的规则，即把数字m和n拼接为mn，nm，只需要按照字符串大小的比较。

python2 自定义排序函数，nums.sort(lambda x, y: cmp(x+y, y+x))
```
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not nums:
            return ''
        # 直接拼接数字，可能导致数值溢出，这是一个隐形的大数问题，需要把数字转换成字符串
        nums = map(str, nums)
        # 把数字m和n拼接为mn，nm，只需要按照字符串大小的比较
        nums.sort(lambda x, y: cmp(y + x, x + y))
        return ''.join(nums).lstrip('0') or '0'

        
```

python3 自定义排序函数，key = cmp_to_key(lambda x, y: int(y + x) - int(x + y))
```
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        if not nums:
            return ''
        nums = map(str, nums)
        key = cmp_to_key(lambda x, y: int(y + x) - int(x + y))
        # lstrip() 方法: 截掉字符串左边的空格或指定字符  0012->12
        res = ''.join(sorted(nums, key=key)).lstrip('0')
        # 000->''
        return res or '0'

```
