因为输入的为有序数组，可以利用其特性
- 最大的为后两位的值
- 最小的为前两位的值
初始化：
head为首，tail为尾
情况：
- 等于
    - 直接返回head+1和tail+1
- 大于
    - tail-1
- 小于
    - head+1


``` Python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        res = []
        if len(numbers) <= 1:
            return None
        head = 0
        tail = len(numbers) - 1
        while tail >= head:
            if (numbers[head] + numbers[tail]) == target:
                res.append(head+1)
                res.append(tail+1)
                break
            elif (numbers[head] + numbers[tail]) > target:
                tail -= 1
                continue
            elif (numbers[head] + numbers[tail]) < target:
                head += 1
                continue
        return res
```
