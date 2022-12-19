越靠前的字母需要移动次数越多，可以算出每个字母需要移动的总次数，然后再对字母进行统一移动处理。时间复杂度为 $O(n)$。

```python
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        length = len(shifts)
        
        # 每个字母要移动的总次数
        num = [0 for _ in range(length)]
        num[length - 1] = shifts[length - 1]
        for i in range(length - 2, -1, -1):
            num[i] = shifts[i] + num[i + 1]
        
        s_list = list(S)
        ord_a = ord('a')
        ord_z = ord('z')
        for i in range(length):
            shift = num[i] % 26
            c = s_list[i]
            ord_res = ord(c) + shift
            if ord_res > ord_z:
                ord_res = ord_res - ord_z - 1 + ord_a
            s_list[i] = chr(ord_res)
        
        return "".join(s_list)
```