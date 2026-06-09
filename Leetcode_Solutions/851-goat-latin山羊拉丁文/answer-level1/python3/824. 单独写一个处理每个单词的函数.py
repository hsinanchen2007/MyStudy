### 解题思路
只有一点需要注意：
首字母分大小写，第一遍没过就是因为忘记大写

### 代码

```python3
class Solution:
    def toGoatLatin(self, S: str) -> str:

        def deal_word(start_char, rest_seq, index):
            if start_char in 'aeiouAEIOU':
                new_word = start_char + rest_seq + 'ma' + 'a' * index
            else:
                new_word = rest_seq + start_char + 'ma' + 'a' * index
            return new_word
        
        s_list = S.split()
        new_seq = []
        for idx, word in enumerate(s_list):
            start_char = word[0]
            rest_seq = word[1:]
            index = idx+1
            new_seq.append(deal_word(start_char, rest_seq, index))
        
        return ' '.join(new_seq)
```