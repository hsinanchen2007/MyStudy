### 解题思路
通过dict初始化键值对，虽占一定内存，但可优化查询效率，可根据实际情况选择策略；
将输入数字字符串转换为对应的字符串列表；
将用于保存结果的列表中各个字符串的尾部追加通过遍历列表中的各个字符串得到的字符，便可求解

### 代码

```python3
class Solution:
    def letterCombinations(self, digits):
        map_letter = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
        }
        result, middle_result = [''], []
        letter_list = [map_letter[item] for item in digits]

        for string in letter_list:
            for item in result:
                for letter in string:
                    middle_result.append(item + letter)
            result, middle_result = middle_result, []
        if result[0] == '':
            return []
        return result
                
```