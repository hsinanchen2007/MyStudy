### 解题思路
解法是用回溯的方式，在循环里面套了递归调用。
![image.png](https://pic.leetcode-cn.com/5219916a0556cdcbc2cff8c3c55701db8dbeec75afc0ade2e8639ad9cdc93b0b-image.png)


### 代码

```python
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """

        dict_map = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}

        def backtrace(letter_str, digits_str):
            if len(digits_str) == 0:
                output.append(letter_str)
            else:
                for letter in dict_map[digits_str[0]]:
                    backtrace(letter_str+letter, digits_str[1:])


        init_str = ""
        output = []
        if len(digits) == 0:
            return []
        else:
            backtrace(init_str,digits)

        return output
```