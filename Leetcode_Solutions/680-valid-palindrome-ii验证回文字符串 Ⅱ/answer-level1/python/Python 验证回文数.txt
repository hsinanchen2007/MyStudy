### 解题思路
此处撰写解题思路
主要是用了Python便捷的切片操作，s[::-1]便可把字符串倒置，若为回文数即s == s[::-1]
由于可以删除一个字母构成回文数，那么我们就可以用双指针扫描到不对称的地方，
再截取s[i,j] 和 s[i+1,j+1]字符串
s[i,j]即截取i到j-1，s[i+1,j+1]即截取到 i+1 到 j 
再通过上述的回文数判断方法判断
### 代码

```python
class Solution(object):
    def validPalindrome(self, s):
        i = 0
        j = len(s) - 1
        if s == s[::-1]:
            return True
        while(i <= j):
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                s1 = s[i:j]
                s2 = s[i+1:j+1] 
                if (s1 == s1[::-1]) or (s2 == s2[::-1]):
                    return True
                else:
                    return False

```