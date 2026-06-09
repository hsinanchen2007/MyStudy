### 解题思路
貌似比官方的解法要快些

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        """
        给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。
        假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。
        注意：每次拼写时，chars 中的每个字母都只能用一次。
        返回词汇表 words 中你掌握的所有单词的 长度之和。
        :param words:
        :param chars:
        :return:
        """
        dt = {}
        # 先建字典，将chars的字符计数并储存，键为字符，值为字符个数
        for char in chars:
            if dt.get(char) is None:
                dt[char] = 1
            else:
                dt[char] += 1

        # print(dt)
        dt_bk = dt.copy()
        result = ""

        # 遍历words
        for word in words:
            # 判断是否将整个word遍历完毕
            key = True

            #  判断每一个word中的每一个字符是否在字典中
            for char in word:
                # 如果在字典中，字符计数减一，否则退出当前word的遍历，不满足条件，key=False
                if dt.get(char):
                    dt[char] -= 1

                else:
                    key = False
                    break

            if key:
                result += word

            #  重置字典
            dt = dt_bk.copy()

        # print(result)
        return len(result)
```