### 解题思路

使用回溯的算法，尝试替换前i个字符为数字，然后递归剩下的字符
定义回溯函数为backtrance(cur, i), cur表示i之前字符替换的结果，i表示已经处理到word的第i位
那么对于"word", 调用backtrance('', 0)
- backtrance('', 0)
    - 不替换， 递归调用backtrance('w', 1)
    - 替换'w'为'1', 递归调用backtrace('1', 1)
    - 替换'wo'为'2', 递归调用backtrace('2', 2)
    - ...

- 对于backtrace('1', 1)
    - 由于前面是'1', 所以不能替换为数字, 直接调用backtrace('1o', 2)

...
    



### 代码
```python
class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        ans = []
        def backtrace(cur='', i=0):
            if i == len(word):
                ans.append(cur)
                return
            
            backtrace(cur + word[i], i+1)
            if not (cur and cur[-1].isdigit()):
                for j in range(i, len(word)):
                    backtrace(cur+str(j-i+1), j+1)
        backtrace()
        return ans



```