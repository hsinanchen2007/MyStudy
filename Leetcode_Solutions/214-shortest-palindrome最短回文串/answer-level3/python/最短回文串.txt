### 解题思路
1.
暴力解法：先遍历找出最长的初始回文串，再将剩余的非回文串部分逆转放在字符串前
2.
双指针与递归：通过双指针与递归算法减少寻找初始回文串所需遍历的字符串的长度，然后再利用暴力解法找出最长的初始回文串
3.
KMP算法：
### 代码

```python3
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        def get_table(p):
            table = [0] * len(p)
            i = 1
            j = 0
            while i < len(p):
                if p[i] == p[j]:
                    j += 1
                    table[i] = j
                    i += 1
                else:
                    if j > 0:
                        j = table[j - 1]
                    else:
                        i += 1
                        j = 0
            return table

        table = get_table(s + "#" + s[::-1])
        return s[table[-1]:][::-1] + s

'''
作者：powcai
链接：https://leetcode-cn.com/problems/shortest-palindrome/solution/zui-duan-hui-wen-chuan-by-powcai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
```