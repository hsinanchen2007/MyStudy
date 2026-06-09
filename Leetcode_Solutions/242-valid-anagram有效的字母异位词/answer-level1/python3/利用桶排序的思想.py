### 解题思路
使用两个计数数组分别统计s和t中的字符的个数，当两个数组相等时，那么s与t是字母异位词

### 代码

```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #创建两个计数数组
        l1 = [0]*26
        l2 = [0]*26
        #将字符串中的字符放入对应的位置
        for i in s:
            l1[ord(i)-ord('a')]+=1
        for j in t: 
            l2[ord(j)-ord('a')]+=1
        #如果两个数组相同则返回True
        if l1 == l2:
            return True
        else:
            return False
```
