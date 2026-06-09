### 解题思路
python双指针方法

### 代码

```python3
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr.sort()
        if len(arr) == 2 and arr[0]!=arr[1]:
            return False
        else:
            i = 0
            j = 0
            l = []
            while j < len(arr) :
                if arr[i] == arr[j]:
                    j = j + 1
                else:
                    num = j - i
                    i = j
                    if num not in l:
                        l.append(num)
                    else:
                        return False
            return True
```