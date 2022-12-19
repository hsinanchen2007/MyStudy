### 解题思路
关键：限定范围
优点：针对大字符串的运算优势明显。
问题：非最优解，当字符串较短时不划算。

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        s_list='qwertyuiopasdfghjklzxcvbnm'
        index_list=[]
        for letter in s_list:
            if  s.count(letter)==1:
                index_list.append(s.index(letter))
        return min(index_list) if index_list else -1
```