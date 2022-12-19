思路很简单，把列表转换成字符串，再转成整数，然后加1得到结果，再转成列表返回
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return [int(i) for i in str(int(''.join(str(i) for i in digits))+1)]
```
