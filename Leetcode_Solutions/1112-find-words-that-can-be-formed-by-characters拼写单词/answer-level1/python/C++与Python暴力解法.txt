### 解题思路
很暴力的解法，python写的有点捉急

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int num = 0;
        int flag = 0;
        int chars_array[chars.length()];
        memset(chars_array, 0, sizeof(chars_array));
        for (auto iter = words.begin(); iter != words.end(); iter++)
        {
            flag = 1;
            for (int i = 0; i < (*iter).length(); i++)
            {
                int j = 0;
                for (j = 0; j < chars.length(); j++)
                {
                    if ((*iter)[i] == chars[j] && chars_array[j] != 1)
                    {
                        chars_array[j] = 1;
                        break;
                    }
                }
                if (j == chars.length())
                {
                    memset(chars_array, 0, sizeof(chars_array));
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                memset(chars_array, 0, sizeof(chars_array));
                num += (*iter).length();
            }
        }
        return num;
    }
};
```

```python
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        num = 0
        chars = list(chars)
        for w in words:
            temp = 0
            chars_t = chars.copy()
            for s in w:
                if s in chars_t:
                    chars_t.remove(s)
                    temp += 1
            if temp == len(w):
                num += len(w)
        return num
```