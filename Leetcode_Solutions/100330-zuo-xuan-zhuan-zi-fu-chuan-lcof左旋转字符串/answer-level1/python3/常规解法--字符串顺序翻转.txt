### 解题思路
python使用这种方法，既不能节省内存也不能提升速度。只作为一种常规解法，以做了解

    ex: 'abcdefg'    k = 2
        ①：翻转前两位'ab' , 得'bacdefg'
        ②：翻转其余字符串'cdefg' , 得'bagfedc'
        ①：整体翻转, 得'cdefgab'

### 代码

```
# 限制条件1 <= k < s.length <= 10000
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        ans = ''
        ans += self.reverse(s[:n])
        ans += self.reverse(s[n:])
        ans = self.reverse(ans)
        return ans

    #reverse 函数翻转传入得字符串s 
    def reverse(self,s):
        n = len(s)
        flag = ''
        while n != 0:
            flag += s[n-1]
            n -=1
        return flag
```