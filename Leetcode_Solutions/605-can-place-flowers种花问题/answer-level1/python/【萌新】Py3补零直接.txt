### 解题思路
类似于之前写的烟囱题目。 在首尾补充0后，步长为2遍历列表，满足没有3位都是0就可以种花

### 代码

```python3
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        nums = [0] + flowerbed + [0]
        i = 1
        count = 0
        while i < len(flowerbed)+1:
            if nums[i-1] == 0 and nums[i] == 0 and nums[i+1] == 0:
                count += 1
                i += 2
            else:
                i += 1
        return count >= n
```