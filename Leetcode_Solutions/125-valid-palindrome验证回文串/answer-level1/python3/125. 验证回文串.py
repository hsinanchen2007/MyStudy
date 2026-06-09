### 解题思路
一把***，双指针双向扫描，跳过除字母与数字字符以外的字符，大写字母转为小写字母。时间复杂度为O(N)，空间复杂度为O(1)。

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 跳过除字母与数字字符以外的字符，大写字母转为小写字母
        # 两端扫描
        pHead,pEnd = 0,len(s)-1
        while pHead<pEnd:
            while pHead<pEnd and not (s[pHead].isdigit() or s[pHead].isalpha()):
                pHead+=1
            while pHead<pEnd and not (s[pEnd].isdigit() or s[pEnd].isalpha()):
                pEnd-=1
            tmp1,tmp2=s[pHead],s[pEnd]
            if tmp1.isupper():
                tmp1 = tmp1.lower()
            if tmp2.isupper():
                tmp2 = tmp2.lower()
            if tmp1!=tmp2:
                return False
            pHead+=1
            pEnd-=1
        return True
```