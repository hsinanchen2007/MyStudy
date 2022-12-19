1. 建立dict表
2. 循环digits，查字典，做拼接

```python []
def letterCombinations(digits: str) -> [str]:
    dict = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }

    def fuse(list1: [str], list2: [str]) -> [str]:
        if list1 == [] and list2 != []:
            return list2
        elif list1 != [] and list2 == []:
            return list1
        elif list1 == [] and list2 == []:
            return []
        else:
            fusestr = []
            for i in list1:
                for j in list2:
                    fusestr.append(i + j)
            return fusestr


    if not digits:
        return []
    if len(digits) == 1:
        return [x for x in dict[digits[0]]]
    else:
        res = []
        for i in digits:
            channl = []
            # print(i)
            for x in dict[i]:
                channl.append(x)
            # print(channl)
            res = fuse(res,channl)
            # print(res)
        return res

```

