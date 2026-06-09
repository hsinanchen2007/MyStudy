采用对撞指针，如对注释有疑惑，欢迎一起交流~
```
class Solution:
    def reverseVowels(self, s: str) -> str:
        # 使用.join将列表中的元素组合成字符串
        # 先将字符串转换为列表
        srr = list(s)
        # 设置元音字母组成的数组
        aeiou = ['a','e','i','o','u','A','E','I','O','U']
        # 设置对撞指针p0，p1
        p0 = 0
        p1 = len(s) - 1
        # 当p0<p1时，若p0为非元音字母，右移；p1为非元音字母，左移；若p0，p1均为元音字母，交换
        while p0 < p1:
            if p0 < p1 and srr[p0] not in aeiou:
                p0 += 1
            elif p0< p1 and srr[p1] not in aeiou:
                p1 -= 1
            else:
                srr[p0],srr[p1] = srr[p1],srr[p0]
                p0 += 1
                p1 -= 1
        return ''.join(srr)
```