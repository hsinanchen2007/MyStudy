### 解题思路
此处撰写解题思路
建一个列表将其装分子分母
### 代码

```python3
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        li = [cont[-1], 1]
        for i in range(len(cont)-1, 0, -1):
            tem = li[1]
            li[1] = li[0]
            li[0] = cont[i-1]*li[1] + tem
            print(li)
        return li
```