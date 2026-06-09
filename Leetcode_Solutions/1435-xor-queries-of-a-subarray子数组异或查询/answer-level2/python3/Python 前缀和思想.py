### 解题思路
> 0 与 任何数 A 异或都等于 A
> 任何数异或它自己都为 0
> 异或公式 A xor B = C => A xor C = B => C xor B = A
${XOR(0 - j) = XOR(0 - i)异或 XOR(i - j) => XOR(i - j) = XOR(0 - i) 异或 XOR(0 - j)}$


### 代码
```python
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        xor_arr = [0]
        for index, item in enumerate(arr, 1):
            xor_arr.append(item ^ xor_arr[index - 1])
        res = []
        for l, r in queries:
            res.append(xor_arr[r + 1] ^ xor_arr[l])
        return res
            
```