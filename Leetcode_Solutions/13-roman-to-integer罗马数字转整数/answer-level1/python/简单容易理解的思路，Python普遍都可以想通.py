简而言之，将str列表化，读取列表前两个元素并字符相加，如果存在于romans列表，就从nums列表找到对应的数字相加，否则在nums找到数字单独相加，最后列表都取切片，排除读取过的.
```
class Solution:
    def romanToInt(self, s: str) -> int:
        nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        romans = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        
        intNum = 0
        sList = list(s)
        while sList:
            if len(sList) == 1:
                intNum += nums[romans.index(sList[0])]
                sList = []
            else:
                if (sList[0] + sList[1]) in romans:
                    intNum += nums[romans.index(sList[0] + sList[1])]
                    sList = sList[2:]
                else:
                    intNum += nums[romans.index(sList[0])]
                    sList = sList[1:]
        return intNum
```