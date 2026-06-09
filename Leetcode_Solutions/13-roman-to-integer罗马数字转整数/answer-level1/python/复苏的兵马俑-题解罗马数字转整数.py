### 题解思路1（正则匹配法）
LeetCode中提交执行结果-执行用时：376 ms，内存消耗：13.5 MB。

### 代码
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        import re
        roman_dict = {
            'IV': 4,
            'IX': 9,
            'XL': 40,
            'XC': 90,
            'CD': 400,
            'CM': 900,
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        num = 0
        while s:
            for key in roman_dict:
                if re.match(key,s):
                    num += roman_dict[key]
                    if len(key) == 1:
                        s = s[1:]
                    if len(key) == 2:
                        s = s[2:]
                        break
                else:
                    continue
        return num
```

### 测试代码
```python
print('“III”对应的整数为：{}'.format(Solution().romanToInt('III')))
print('“IV”对应的整数为：{}'.format(Solution().romanToInt('IV')))
print('“IX”对应的整数为：{}'.format(Solution().romanToInt('IX')))
print('“LVIII”对应的整数为：{}'.format(Solution().romanToInt('LVIII')))
print('“MCMXCIV”对应的整数为：{}'.format(Solution().romanToInt('MCMXCIV')))
```

### 运行结果
```python
“III”对应的整数为：3
“IV”对应的整数为：4
“IX”对应的整数为：9
“LVIII”对应的整数为：58
“MCMXCIV”对应的整数为：1994
```

### 题解思路2（正则匹配法优化版）
LeetCode中提交执行结果-执行用时：56 ms，内存消耗：13.5 MB。

### 代码
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        import re
        roman_dict = {
            'I': 1,
            'IV': 4,
            'V': 5,
            'IX': 9,
            'X': 10,
            'XL': 40,
            'L': 50,
            'XC': 90,
            'C': 100,
            'CD': 400,
            'D': 500,
            'CM': 900,
            'M': 1000
        }
        num = 0
        list_s = re.findall('CM|CD|XC|XL|IX|IV|I|V|X|L|C|D|M', s)
        for s in list_s:
            num += roman_dict[s]
        return num
```

### 测试代码
```python
print('“III”对应的整数为：{}'.format(Solution().romanToInt('III')))
print('“IV”对应的整数为：{}'.format(Solution().romanToInt('IV')))
print('“IX”对应的整数为：{}'.format(Solution().romanToInt('IX')))
print('“LVIII”对应的整数为：{}'.format(Solution().romanToInt('LVIII')))
print('“MCMXCIV”对应的整数为：{}'.format(Solution().romanToInt('MCMXCIV')))
```

### 运行结果
```python
“III”对应的整数为：3
“IV”对应的整数为：4
“IX”对应的整数为：9
“LVIII”对应的整数为：58
“MCMXCIV”对应的整数为：1994
```

### 题解思路3
LeetCode中提交执行结果-执行用时：52 ms，内存消耗：13.3 MB。

### 代码
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        roman_dict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        num = 0
        for i in range(len(s)):
            if i < len(s) -1 and roman_dict[s[i]] < roman_dict[s[i + 1]]:
                num -= roman_dict[s[i]]
            else:
                num += roman_dict[s[i]]
        return num
```

### 测试代码
```python
print('“III”对应的整数为：{}'.format(Solution().romanToInt('III')))
print('“IV”对应的整数为：{}'.format(Solution().romanToInt('IV')))
print('“IX”对应的整数为：{}'.format(Solution().romanToInt('IX')))
print('“LVIII”对应的整数为：{}'.format(Solution().romanToInt('LVIII')))
print('“MCMXCIV”对应的整数为：{}'.format(Solution().romanToInt('MCMXCIV')))
```

### 运行结果
```python
“III”对应的整数为：3
“IV”对应的整数为：4
“IX”对应的整数为：9
“LVIII”对应的整数为：58
“MCMXCIV”对应的整数为：1994
```

### 题解思路4
LeetCode中提交执行结果-执行用时：60 ms，内存消耗：13.4 MB。

### 代码
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        roman_dict = {
            'I': 1,
            'IV': -1,
            'V': 5,
            'IX': -1,
            'X': 10,
            'XL': -10,
            'L': 50,
            'XC': -10,
            'C': 100,
            'CD': -100,
            'D': 500,
            'CM': -100,
            'M': 1000
        }
        return sum(roman_dict.get(s[i: i + 2], roman_dict[s[i]]) for i in range(len(s)))
```

### 测试代码
```python
print('“III”对应的整数为：{}'.format(Solution().romanToInt('III')))
print('“IV”对应的整数为：{}'.format(Solution().romanToInt('IV')))
print('“IX”对应的整数为：{}'.format(Solution().romanToInt('IX')))
print('“LVIII”对应的整数为：{}'.format(Solution().romanToInt('LVIII')))
print('“MCMXCIV”对应的整数为：{}'.format(Solution().romanToInt('MCMXCIV')))
```

### 运行结果
```python
“III”对应的整数为：3
“IV”对应的整数为：4
“IX”对应的整数为：9
“LVIII”对应的整数为：58
“MCMXCIV”对应的整数为：1994
```

### 题解思路5
LeetCode中提交执行结果-执行用时：88 ms，内存消耗：13.6 MB。

### 代码
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        roman_dict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        result = 0
        prev_num = 0
        for i in reversed(s):
            num = roman_dict.get(i)
            if num < prev_num:
                result -= num
            else:
                result += num
                prev_num = num
        return result
```

### 测试代码
```python
print('“III”对应的整数为：{}'.format(Solution().romanToInt('III')))
print('“IV”对应的整数为：{}'.format(Solution().romanToInt('IV')))
print('“IX”对应的整数为：{}'.format(Solution().romanToInt('IX')))
print('“LVIII”对应的整数为：{}'.format(Solution().romanToInt('LVIII')))
print('“MCMXCIV”对应的整数为：{}'.format(Solution().romanToInt('MCMXCIV')))
```

### 运行结果
```python
“III”对应的整数为：3
“IV”对应的整数为：4
“IX”对应的整数为：9
“LVIII”对应的整数为：58
“MCMXCIV”对应的整数为：1994
```