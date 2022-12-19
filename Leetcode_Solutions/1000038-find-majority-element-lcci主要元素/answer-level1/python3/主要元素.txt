### 解题思路
还有一种思路：如果一个数过半，那么nums中间那个数字必然是这个过半的数，所以先给数组元素排序，获取最中间那个数，看它出现的频数是否过半。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = collections.Counter(nums)
        for key,value in dic.items():
            if value > (len(nums) / 2):
                return key
        return -1
```