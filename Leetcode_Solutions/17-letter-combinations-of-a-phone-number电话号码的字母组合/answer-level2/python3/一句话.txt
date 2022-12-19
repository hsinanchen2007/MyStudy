一句话实现功能，笛卡尔积。
```python []
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        num_letter_mapping = {'2': 'abc',
                             '3': 'def',
                             '4': 'ghi',
                             '5': 'jkl',
                             '6': 'mno',
                             '7': 'pqrs',
                             '8': 'tuv',
                             '9': 'wxyz'}
        return list(filter(lambda x: True if x else False, [''.join(i) for i in itertools.product(*[num_letter_mapping[digit] for digit in digits])]))

```
