```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}

        def get_combine(existed_list, remain_str):
            if remain_str:
                new_list = []
                for new_item in phone[remain_str[0]]:
                    for existed_item in existed_list:
                        new_list.append(existed_item+new_item)

                return get_combine(new_list, remain_str[1:])
            else:
                return existed_list


        if digits:
            return get_combine([''], digits)
        return []
```

递归的时间和回溯差不多。对有些人来说更好理解。
