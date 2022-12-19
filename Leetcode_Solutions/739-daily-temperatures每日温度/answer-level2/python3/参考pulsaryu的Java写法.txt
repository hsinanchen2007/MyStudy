```python
def dailyTemperatures(self, T: List[int]) -> List[int]:
        res, length, i = [0] * len(T), len(T), len(T) - 2
        while i >= 0:
            j = i + 1
            while j < length:
                if T[i] < T[j]:
                    res[i] = j - i
                    break
                else:
                    if res[j] == 0:
                        res[i] = 0
                        break
                    else:
                        j += res[j]
            i -= 1
        return res
```[@pulsaryu](/u/pulsaryu)
