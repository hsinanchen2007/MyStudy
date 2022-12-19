### 解题思路
双指针取连续个数大于等于三的元素的头尾索引
注意，为保证取到最后一个元素，str末尾添加‘0’元素

### 代码

```python3
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        i, j = 0, 1
        ans = []
        S = S + '0'
        while j < len(S):
            if S[i] == S[j]:
                j += 1
            else:
                if j-i >= 3:
                    ans.append([i,j-1])
                i = j
                j += 1
        return ans
```