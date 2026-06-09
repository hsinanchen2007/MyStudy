![image.png](https://pic.leetcode-cn.com/10f13a37d7a669c8934262c1a367a8536de522a6baaaf50ff3ea1366064cb79c-image.png)
思路：将字符串倒置，从头遍历，遇到空格就跳出
```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s[::-1]
        nums = 0
        for i in s:
            if i == " ":
                if  nums != 0:
                    return nums
            else :
                nums += 1
        return nums
```

后面加上了以空格结尾的情况

