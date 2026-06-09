### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        #设置两个指针指向数组的开头和末尾
        low , high = 0 , len(numbers) - 1 
        for i in range(len(numbers)-1):
            if numbers[low] + numbers[high] == target:
                return [low+1,high+1]
            if numbers[low] + numbers[high] < target:
                low += 1
            if numbers[low] + numbers[high] > target:
                high -= 1
        return None
```