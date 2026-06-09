由于罗马数字在整数每个位置（个位、十位...）上都有一样的模式，（即 1, 11, 111, 15, 51...），因此对每个位置查找出对应模式，再分别带入个位、十位...的对应罗马字母即可。
```
class Solution:
    def intToRoman(self, num: int):
        if (num <= 0 or num >= 4000):
            print('out of range (1-3999) convertor can process %d' % (num))
            return ""

        numPattern = ['', '0', '00', '000', '01', '1', '10', '100', '1000', '02']
        romanGroup = ['M', 'CDM', 'XLC', 'IVX']
        result = ''
        group = 0
        for exp in [1000, 100, 10, 1]:
            i = (num // exp) % 10
            for c in numPattern[i]:
                result += romanGroup[group][int(c)]
            group += 1

        print('converted %d ==> [%s]' % (num, result))
        return result
```

执行用时 :80 ms, 在所有 Python3 提交中击败了75.22%的用户
内存消耗 :13.2 MB, 在所有 Python3 提交中击败了80.89%的用户