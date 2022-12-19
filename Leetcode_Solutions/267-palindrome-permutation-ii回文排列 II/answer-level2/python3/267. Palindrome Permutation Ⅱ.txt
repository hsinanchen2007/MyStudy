### 解题思路
执行用时：36ms
内存消耗：12.9MB

**暴力解法：**
Back Tracking产生所有的排列情况，再判断是否是回文串

**优化：**
先判断是否能产生回文串
1. 不能产生回文串：
    1. 判断：有两个及以上的字符出现次数为单数
    2. 处理：直接输出[]
    3. 在这个过程中把单数的字符记录下来，若能产生回文串，则这个字符必须作为中间字符
1. 能产生回文串：
    1. 在判断的过程中生成even_char字符串，记录双数字符以及出现的次数的一半（因为生成回文串的一半即可）。这里注意出现次数为单数的字符减去1后若还有剩余也需要记为单数字符。
    2. 对于even_char字符串用回溯法生成全排列，只用生成一半的字符串即可，若存在单数出现的字符则放中间，后一半是前一半的倒序排列
### 代码

```python3
import collections
class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        char_count = collections.Counter(s)
        odd_char = ''
        even_char = ''
        for char in char_count:
            if char_count[char] % 2 != 0:
                odd_char += char
                char_count[char] -= 1
            if len(odd_char) > 1:
                return []
            even_char += char * (char_count[char] // 2)
        
        self.res = []
        visited = [False for _ in range(len(even_char))]
        self.BackTracking(even_char, '', visited, odd_char)
        return self.res


    def BackTracking(self, even_char, sub_string, visited, odd_char):
        if len(sub_string) == len(even_char):
            s = sub_string + odd_char + sub_string[::-1]
            self.res.append(s)
            return
        
        for i in range(len(even_char)):
            if visited[i]:
                continue
            if i > 0 and even_char[i] == even_char[i - 1] and not visited[i - 1]:
                continue
            sub_string += even_char[i]
            visited[i] = True
            self.BackTracking(even_char, sub_string, visited, odd_char)
            visited[i] = False
            sub_string = sub_string[:-1]
```