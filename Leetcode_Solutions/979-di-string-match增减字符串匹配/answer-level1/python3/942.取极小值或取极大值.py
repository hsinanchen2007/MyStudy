### 解题思路
1. 当我们需要决定一个位置的数字时，根据的信息是“当前位置和下一个位置的数字大小关系”。
2. 如果要求是递增的，那么只要确保当前选择的是剩余可选范围内最小的那个，那么下一个位置上，在剩余的数字中不管选哪个都能保证比当前位置的更大。
3. 递减同理。
4. 所以需要维护一个“剩余可选的数字范围”，每次要么从中取出最小的那个，要么取出最大的那个，所以只需要记录这个范围的最小值和最大值即可。

### 代码

```python3
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        arr = [_ for _ in range(len(S) + 1)]
        res = []

        for letter in S:
            if letter == 'I':
                res.append(arr.pop(0))
            if letter == 'D':
                res.append(arr.pop(-1))

        
        res.append(arr[0])
        return res
```