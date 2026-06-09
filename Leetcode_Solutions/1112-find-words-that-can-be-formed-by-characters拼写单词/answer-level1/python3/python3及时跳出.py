### 解题思路
python3及时跳出

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        import copy
        chars_dict = {}
        for item in chars:
            chars_dict[item] = chars_dict.get(item, 0) + 1
        len_chars = len(chars)
        ret_count = 0

        for word in words:
            if len(word) <= len_chars:
                tmp_dict = copy.copy(chars_dict)
                is_ok  = True
                for ch in word:
                    if ch not in tmp_dict or tmp_dict[ch] == 0:
                        is_ok = False
                        break
                    else:
                        tmp_dict[ch] -= 1
                if is_ok:
                    ret_count += len(word)

        return ret_count

```