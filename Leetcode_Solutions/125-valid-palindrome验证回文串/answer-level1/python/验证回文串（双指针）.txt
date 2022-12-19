### 解题思路
设置一个头指针和一个尾指针
头指针从头开始找，找到第一个数字或字符
尾指针从尾开始找，找到最后一个数字或字符
比较两者是否相同，不同就return False
相同则两指针往中间靠
当 i > j 的时候，return True

复杂度分析
时间复杂度 O(N)O(N), 遍历一遍数组。
空间复杂读 O(1)O(1)，只使用了常量的空间。

### 代码

```python3
class Solution:
#方法一  头尾指针分别向中间检查
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            while i < len(s) and not s[i].isalnum():
                i += 1
            while j > -1 and not s[j].isalnum():
                j -= 1
            if i > j:
                return True
            if s[i].upper() != s[j].upper():
                return False
            else:
                i += 1
                j -= 1
        return True

#方法二  正则表达式提取字母和数字，直接比较
def isPalindrome2(self, s: str) -> bool:
        tmp = re.sub(r"[^A-Za-z0-9]","", s).lower()
        return tmp == tmp[::-1]
```

代码
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            while i < len(s) and not s[i].isalnum():
                i += 1
            while j > -1 and not s[j].isalnum():
                j -= 1
            if i > j:
                return True
            if s[i].upper() != s[j].upper():
                return False
            else:
                i += 1
                j -= 1
        return True