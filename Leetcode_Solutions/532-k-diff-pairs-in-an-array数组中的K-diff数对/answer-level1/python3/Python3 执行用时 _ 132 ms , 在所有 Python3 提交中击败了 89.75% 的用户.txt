### 代码

```python3
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        myset=set(nums) #构造对应的集合
        if k == 0:  #如果k为0，则考虑nums中重复的项，用 sum([1 充当计数器
            return sum([1 for i in myset if nums.count(i)>=2])
        elif k<0:
            return 0 #两个数的差的绝对值不可能为负数
        # 如果k不为0，则需要忽略nums中重复的项
        # 不需要验证j-i==k，只需要查找i+k是否在集合中即可省略for j in myset的做法
        return sum(1 for i in myset if k+i in myset)
```