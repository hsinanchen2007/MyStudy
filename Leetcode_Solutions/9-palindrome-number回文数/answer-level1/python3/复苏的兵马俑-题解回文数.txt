### 常规（转字符串）

### 题解思路1（转字符串法）
LeetCode中提交执行结果-执行用时：52 ms，内存消耗：13.6 MB。

### 代码
```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            str_x = str(x)
            if str_x[::-1] == str_x:
                return True
            else:
                return False
```

### 测试代码
```python3
print('整数121{}回文数！'.format('是' if Solution().isPalindrome(121) else '不是'))
print('整数-121{}回文数！'.format('是' if Solution().isPalindrome(-121) else '不是'))
print('整数10{}回文数！'.format('是' if Solution().isPalindrome(10) else '不是'))
```

### 运行结果
```python3
121是回文数！
-121不是回文数！
10不是回文数！
```

### 题解思路2（思路1代码优化）
LeetCode中提交执行结果-执行用时：88 ms，内存消耗：13.4 MB。

### 代码
```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return True if str(x) == str(x)[::-1] else False
```
### 测试代码
```python3
print('整数121{}回文数！'.format('是' if Solution().isPalindrome(121) else '不是'))
print('整数-121{}回文数！'.format('是' if Solution().isPalindrome(-121) else '不是'))
print('整数10{}回文数！'.format('是' if Solution().isPalindrome(10) else '不是'))
```
### 运行结果
```python3
121是回文数！
-121不是回文数！
10不是回文数！
```

### 题解思路3（列表反转法）
LeetCode中提交执行结果-执行用时：92 ms，内存消耗：13.4 MB。

### 代码
```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        list_x = list(str(x))
        list_x.reverse()
        return True if list_x == list(str(x)) else False
```

### 测试代码
```python
print('整数121{}回文数！'.format('是' if Solution().isPalindrome(121) else '不是'))
print('整数-121{}回文数！'.format('是' if Solution().isPalindrome(-121) else '不是'))
print('整数10{}回文数！'.format('是' if Solution().isPalindrome(10) else '不是'))
```

###运行结果
```python3
121是回文数！
-121不是回文数！
10不是回文数！
```

### 题解思路4（反转整数法）
LeetCode中提交执行结果-执行用时：136 ms，内存消耗：13.6 MB。

### 代码
```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            y = x
            reverse_x = 0
            while y != 0:
                reverse_x = reverse_x * 10 + y % 10
                y = y // 10
            if reverse_x == x:
                return True
            else:
                return False
```

### 测试代码
```python3
print('整数121{}回文数！'.format('是' if Solution().isPalindrome(121) else '不是'))
print('整数-121{}回文数！'.format('是' if Solution().isPalindrome(-121) else '不是'))
print('整数10{}回文数！'.format('是' if Solution().isPalindrome(10) else '不是'))
```

### 运行结果
```python3
121是回文数！
-121不是回文数！
10不是回文数！
```

### 题解思路5（双向队列法）
LeetCode中提交执行结果-执行用时：80 ms，内存消耗：13.5 MB。

### 代码
```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        list_x = list(str(x))
        while len(list_x) > 1:
            if list_x.pop(0) != list_x.pop():
                return False
        return True
```

### 测试代码
```python3
print('整数121{}回文数！'.format('是' if Solution().isPalindrome(121) else '不是'))
print('整数-121{}回文数！'.format('是' if Solution().isPalindrome(-121) else '不是'))
print('整数10{}回文数！'.format('是' if Solution().isPalindrome(10) else '不是'))
```

### 运行结果
```python3
121是回文数！
-121不是回文数！
10不是回文数！
```

### 题解思路6（双指针法）
LeetCode中提交执行结果-执行用时：148 ms，内存消耗：13.5 MB。

### 代码
```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        list_x = list(str(x))
        L, R = 0, len(list_x) - 1
        while L <= R:
            if list_x[L] != list_x[R]:
                return False
            L += 1
            R -= 1
        return True
```

### 测试代码
```python3
print('整数121{}回文数！'.format('是' if Solution().isPalindrome(121) else '不是'))
print('整数-121{}回文数！'.format('是' if Solution().isPalindrome(-121) else '不是'))
print('整数10{}回文数！'.format('是' if Solution().isPalindrome(10) else '不是'))
```

### 运行结果
```python3
121是回文数！
-121不是回文数！
10不是回文数！
```

### 进阶（不转字符串）

### 题解思路1（反转整数法）
LeetCode中提交执行结果-执行用时：136 ms，内存消耗：13.6 MB。

### 代码
```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            y = x
            reverse_x = 0
            while y != 0:
                reverse_x = reverse_x * 10 + y % 10
                y = y // 10
            return True if reverse_x == x else False
```

### 测试代码
```python3
print('整数121{}回文数！'.format('是' if Solution().isPalindrome(121) else '不是'))
print('整数-121{}回文数！'.format('是' if Solution().isPalindrome(-121) else '不是'))
print('整数10{}回文数！'.format('是' if Solution().isPalindrome(10) else '不是'))
```
### 运行结果
```python3
121是回文数！
-121不是回文数！
10不是回文数！
```