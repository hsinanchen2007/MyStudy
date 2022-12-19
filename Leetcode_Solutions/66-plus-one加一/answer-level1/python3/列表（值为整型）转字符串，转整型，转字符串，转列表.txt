### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        #"".join(digits)这个报错是因为列表中的为int
        #"".join([str(i) for i in digits])注意格式
        return list(str(int("".join(str(i) for i in digits))+1))

```