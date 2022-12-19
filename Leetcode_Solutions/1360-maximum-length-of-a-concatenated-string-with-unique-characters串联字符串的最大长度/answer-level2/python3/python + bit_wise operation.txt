```python
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        bit_arr = []
        for st in arr:
            num = 0
            for ch in st:
                num = num | (1 << (ord(ch) - 97))
            bit_arr.append(num)

        prefix_arr = [(0, 0)]
        for i, num in enumerate(bit_arr):
            if '{:032b}'.format(num).count('1') != len(arr[i]): continue
            l = len(prefix_arr)
            for j in range(l):
                x, l = prefix_arr[j]
                if num & x == 0:
                    prefix_arr.append((num | x, l + len(arr[i])))
        prefix_arr.sort(key = lambda x: x[1], reverse = True)
        return prefix_arr[0][1]
```