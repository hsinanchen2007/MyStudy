class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        str0 = s[0:n]
        str1 = s[n:]
        return str1+str0
![捕获.PNG](https://pic.leetcode-cn.com/59bc4d795a1d12d17c180aa3fc7aa5dd6225d6d007ae58bb8abffa7e49a2acf8-%E6%8D%95%E8%8E%B7.PNG)
