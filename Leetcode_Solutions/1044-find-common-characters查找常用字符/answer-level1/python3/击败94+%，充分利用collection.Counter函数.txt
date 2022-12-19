### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        cnt=collections.Counter(A[0]) #至少包含一个元素，所有不会报错
        for item in A:
            cnt &= collections.Counter(item)  #按位与
        return sorted(cnt.elements())  #魔法点
```