### 解题思路
注意这里是升序数组；并且下标不以0开始；
1. 令`index1, index2`分别指向`numbers[0], numbers[1]`; 
2. 检查`numbers[index1]+numbers[index2]`与`target`的大小；
3. 如果两数之和大于`target`，则将`index2-=1`；
4. 如果两数之和小于`target`，则将`index1+=1`;

### 代码

```python3
class Solution:
    """
    双指针法：index1，index2开始分别指向numbers[0]和numbers[-1]，如果和大于target，则index2-=1；否则index1+=1；
    """
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if len(numbers) < 2:
            return []
        if len(numbers) == 2:
            if sum(numbers) == target:
                return [1, 2]
            else:
                return []
        
        index1, index2 = 0, len(numbers)-1
        while index1 < index2:
            if numbers[index1] + numbers[index2] == target:
                return [index1+1, index2+1]
            elif numbers[index1] + numbers[index2] < target:
                index1 += 1
            else:
                index2 -= 1
        return []
```