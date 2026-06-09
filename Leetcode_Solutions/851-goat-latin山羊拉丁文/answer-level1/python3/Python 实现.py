1. 利用空格从字符串分割单词
2. 循环遍历所有单词
3. 通过单词首字母区分对单词的操作

```python
class Solution:
    def toGoatLatin(self, S: str) -> str:
        end = 'a'
        
        words = S.split(' ')
        vowel = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        
        length = len(words)
        
        for i in range(length):
            word = words[i]
            if word[0] in vowel:
                words[i] = word
            else:
                words[i] = word[1:] + word[0]
                
            words[i] = words[i] + 'ma' + end
            end += 'a'
        
        return ' '.join(words)
```