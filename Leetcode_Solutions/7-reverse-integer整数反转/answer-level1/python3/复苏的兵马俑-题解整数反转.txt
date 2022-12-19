### 解题思路1（列表反转法）
LeetCode中提交执行结果-执行用时：60 ms，内存消耗：13.3 MB。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        reverse_x = ''
        if x >= 0:
            x = str(x)
            x_list = list(x)
            x_list.reverse()
            for i in x_list:
                reverse_x += i
            reverse_x = int(reverse_x)
        else:
            x = str(x)
            x_list = list(x)[1:]
            x_list.reverse()
            for i in x_list:
                reverse_x += i
            reverse_x = int('-' + reverse_x)
        return reverse_x if -2 ** 31 <= reverse_x <= 2 ** 31 -1 else 0
```
### 测试代码

```python3
reverse_x = Solution().reverse(123)
print('123反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(-123)
print('-123反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(1200)
print('1200反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(-2147483648)
print('-2147483648反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(2147483647)
print('2147483647反转后的结果为：{}'.format(reverse_x))
```
### 运行结果

```python3
123反转后的结果为：321
-123反转后的结果为：-321
1200反转后的结果为：21
-2147483648反转后的结果为：0
2147483647反转后的结果为：0
```

### 解题思路2（字符串切片法）
LeetCode中提交执行结果-执行用时：36 ms，内存消耗：13.5 MB。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        reverse_x = ''
        if x >= 0:
            x = str(x)
            reverse_x = x[::-1]
            reverse_x = int(reverse_x)
        else:
            x = str(x)
            reverse_x = x[:0:-1]
            reverse_x = int('-' + reverse_x)

        return reverse_x if -2 ** 31 <= reverse_x <= 2 ** 31 -1 else 0
```
### 测试代码

```python3
reverse_x = Solution().reverse(123)
print('123反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(-123)
print('-123反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(1200)
print('1200反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(-2147483648)
print('-2147483648反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(2147483647)
print('2147483647反转后的结果为：{}'.format(reverse_x))
```
### 运行结果

```python3
123反转后的结果为：321
-123反转后的结果为：-321
1200反转后的结果为：21
-2147483648反转后的结果为：0
2147483647反转后的结果为：0
```

### 解题思路3（取余反转法）
LeetCode中提交执行结果-执行用时：40 ms，内存消耗：13.5 MB。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        y = abs(x)
        reverse_x = 0
        boundry = (1 << 31) - 1 if x > 0 else 1 << 31
        while y != 0:
            reverse_x = reverse_x * 10 + y % 10
            if reverse_x > boundry:
                return 0
            y //= 10
        return reverse_x if x >= 0 else -reverse_x
```
### 测试代码

```python3
reverse_x = Solution().reverse(123)
print('123反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(-123)
print('-123反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(1200)
print('1200反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(-2147483648)
print('-2147483648反转后的结果为：{}'.format(reverse_x))
reverse_x = Solution().reverse(2147483647)
print('2147483647反转后的结果为：{}'.format(reverse_x))
```
### 运行结果

```python3
123反转后的结果为：321
-123反转后的结果为：-321
1200反转后的结果为：21
-2147483648反转后的结果为：0
2147483647反转后的结果为：0
```
