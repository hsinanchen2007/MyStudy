### 解题思路
枚举法，用`set`对象保存所有的子字符串

执行用时: `1908 ms`, 在所有 `Python3` 提交中击败了`72.35%`的用户
内存消耗: `13.5 MB`, 在所有 `Python3` 提交中击败了`100.00%`的用户

### 代码

```python3
class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        n = len(text)
        all_s = set()
        for i in range(0, n):
            for j in range(i+1,(n-i)//2+i+1):
                if text[i:j] == text[j:2*j-i]:
                    all_s.add(text[i:j])
        
        return len(all_s)

```