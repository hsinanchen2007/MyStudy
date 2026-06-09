### 解题思路
使用正则，分割和提取compressedString中的字母和数字

### 代码

```python3
import re
class StringIterator:

    def __init__(self, compressedString: str):
        self.counter =[int(r) for r in re.split(r'[a-z A-Z]',compressedString)[1:]]
        self.record = re.findall(r'[a-z A-Z]',compressedString)
        self.cur = 0

    def next(self) -> str:
        if self.cur >= len(self.counter):
            return ' '
        if self.counter[self.cur] <= 1:
            self.cur = int(self.cur) + 1
            return self.record[self.cur - 1]
        else:
            self.counter[self.cur] = self.counter[self.cur] - 1
            return self.record[self.cur]

    def hasNext(self) -> bool:
        if self.cur < len(self.record):
            return True
        else:
            return False