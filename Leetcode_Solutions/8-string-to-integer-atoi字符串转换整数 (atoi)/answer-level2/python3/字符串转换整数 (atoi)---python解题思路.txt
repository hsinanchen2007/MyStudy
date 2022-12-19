使用了正则

```python
class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip()
        if str == "" or re.search(r"[-+0-9]+", str[0]) == None:
            return 0
        b = re.findall(r'-?\d+', str)
        if b is not None and len(b) != 0:
            try:
                new_b = int(b[0])
                if new_b < pow(-2, 31) or new_b > pow(2, 31) - 1:
                    return pow(-2, 31) if new_b < 0 else pow(2, 31) - 1
                else:
                    return new_b
            except:
                return pow(-2, 31) if b[0] == "-" else pow(2, 31) - 1
        else:
            return 0
```

结果发现了一个有趣的测试用例

1022 / 1079 个通过测试用例

输入： "+-2"
输出： -2
预期： 0

在这个"+-2"的测试用例的时候出现了问题

于是把b = re.findall进行了一些修改r'^[+-]?\d+'
只有+-开头的，并且只出现其中1个的才符合要求

最终代码

```python
class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip()
        if str == "" or re.search(r"[-+0-9]+", str[0]) == None:
            return 0
        b = re.findall(r'^[+-]?\d+', str)
        if b is not None and len(b) != 0:
            try:
                new_b = int(b[0])
                if new_b < pow(-2, 31) or new_b > pow(2, 31) - 1:
                    return pow(-2, 31) if new_b < 0 else pow(2, 31) - 1
                else:
                    return new_b
            except:
                return pow(-2, 31) if b[0] == "-" else pow(2, 31) - 1
        else:
            return 0
```

运行结果

```
执行用时 :32 ms, 在所有 python3 提交中击败了99.80% 的用户
内存消耗 :13.7 MB, 在所有 python3 提交中击败了5.16%的用户

执行用时 :48 ms, 在所有 python3 提交中击败了75.56% 的用户
内存消耗 :13.9 MB, 在所有 python3 提交中击败了5.16%的用户

执行用时 :48 ms, 在所有 python3 提交中击败了75.56% 的用户
内存消耗 :13.6 MB, 在所有 python3 提交中击败了5.16%的用户
```

正则还是很强大的o(*￣︶￣*)o
欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)