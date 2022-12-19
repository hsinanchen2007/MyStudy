### 解题思路
考虑循环的情况，设置字典记录，记录出现循环的点，一旦出现，就将循环部分直接跳过

### 代码

```python3
class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        ans = 0
        word_pos = 0
        word_length = len(sentence)
        mem = {}
        row = 0
        while row < rows:
            col_pos = 0
            while col_pos < cols:
                word_l = len(sentence[word_pos])
                if cols - col_pos >= word_l:
                    col_pos += word_l + 1
                    word_pos = (word_pos + 1) % word_length
                    if word_pos == 0:
                        ans += 1
                else:
                    break
            if (col_pos, word_pos) not in mem:
                mem[(col_pos, word_pos)] = (row, ans)
            else:
                between_rows = row - mem[(col_pos, word_pos)][0]
                between_cycle = ans - mem[(col_pos, word_pos)][1]
                cycles = (rows - row - 1) // between_rows
                ans += cycles * between_cycle
                row += between_rows * cycles
            row += 1
        return ans
```