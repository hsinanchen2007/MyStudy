### 解题思路
极简

python3 自带list计数函数count
count用法:
list名字.count(查找的值)
count_e.g:
arr.count(1)
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return nums.count(target)
```